//
// Created by jaime on 2020/9/6.
//

#ifndef QUEUE_COMSUMER_H
#define QUEUE_COMSUMER_H
#include "../CircleQueue.h"
#include <sys/socket.h>
#include <cstdio>
#include <cerrno>

const int MAX_QUEUE = 100;

class Comsumer {
public:
    Comsumer(){
        m_queue = new CircleQueue<int>(MAX_QUEUE);
        int sock = socketpair(AF_UNIX,SOCK_DGRAM,0,m_pair_fd);
        if ( sock < 0){
            printf("socker error is %d\n",errno);
            return;
        }
    };
    ~Comsumer() = default;

public:
    bool put_task(int data);
    void comsume();
    int get_sum(){
        return m_sum;
    }
private:
    void notify();
private:
    CircleQueue<int>* m_queue = nullptr;
    int m_pair_fd[2] = {0,0};
    int m_sum = 0;
};


#endif //QUEUE_COMSUMER_H
