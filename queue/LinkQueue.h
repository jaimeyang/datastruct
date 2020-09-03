//
// Created by jaime on 2020/8/31.
//

#ifndef QUEUE_LINKQUEUE_H
#define QUEUE_LINKQUEUE_H

#include <memory>

using namespace std;

template<typename T>
struct LNode{
    T data;
    LNode<T>*   next;
};

template<typename T>
class LinkQueue {
public:
    LinkQueue(int max_size):
    m_max_size(max_size){

    }
    ~LinkQueue(){

    }

    int enqueue(T data){

    }

private:
    int m_max_size = 0;
    unique_ptr<>LNode<T>* m_head = nullptr;
    LNode<T>* m_tail = nullptr;
};


#endif //QUEUE_LINKQUEUE_H
