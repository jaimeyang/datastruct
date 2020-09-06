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
    LNode<T>*  next;
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
        if ( m_count >= m_max_size ){
            return -1;
        }else{
            auto node = new LNode<T>();
            node->data = data;
            node->next = nullptr;
            if ( m_count > 0 ){
                m_tail->next = node;
            }else{
                m_head = node;
            }
            m_tail = node;
            m_count++;
            return 0;
        }
    }

    bool dequeue(T& data){
        if ( m_count <= 0 ){
            return false;
        }else{
            auto node = m_head;
            m_head = node->next;
            m_count--;
            data = node->data;
            delete node;
            return true;
        }
    }

private:
    int m_max_size = 0;
    int m_count = 0;
    LNode<T>* m_head = nullptr;
    LNode<T>* m_tail = nullptr;
};


#endif //QUEUE_LINKQUEUE_H
