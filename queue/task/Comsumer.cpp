//
// Created by jaime on 2020/9/6.
//

#include <unistd.h>
#include <cstring>
#include <iostream>
#include "Comsumer.h"

bool Comsumer::put_task(int data) {
    bool flag = false;
    if ( m_queue->is_empty() ){
        flag = true;
    }
    if ( m_queue->enqueue(data) ){
        if ( flag ){
            notify();
        }
        return true;
    }
    return false;
}

void Comsumer::comsume() {
    while (true){
//        if ( m_queue->is_empty() ){
//            char buf[1];
//            //todo 设置超时时间
//            read(m_pair_fd[1],buf,1);
//        }
        int data = 0;
        if ( m_queue->dequeue(data) ){
            m_sum += data;
            std::cout<<"data is "<<data<<std::endl;
        }
    }
}

void Comsumer::notify() {
    char* buf = "a";
    write(m_pair_fd[0],buf,strlen(buf));
}
