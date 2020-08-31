//
// Created by jaime on 2020/8/27.
//

#ifndef QUEUE_ARRAYQUEUE_H
#define QUEUE_ARRAYQUEUE_H

template<typename T>
struct ANode{
    T   data;
};

template<typename T>
class ArrayQueue {
public:
    ArrayQueue(int size):
    m_max_size(size){
        m_queue = new ANode<T>*[size];
        for (int i = 0; i < size; ++i) {
            m_queue[i] = new ANode<T>();
        }
    }

    ~ArrayQueue(){

    }

public:
    //入队列，不够就搬移数据
    int enqueu(T data){
        if ( m_tail >= m_max_size ){
            if ( m_head == 0 ){
                return -1;
            }
            for (int i = m_head; i < m_tail; ++i) {
                m_queue[i - m_head]->data = m_queue[i]->data;
            }
            m_tail -= m_head;
            m_head = 0;
        }
        m_queue[m_tail]->data = data;
        m_tail++;
        return 0;
    }

    //出队
    ANode<T>* dequeue(){
        if ( m_tail <= 0 ){
            return nullptr;
        }else{
            auto node = m_queue[m_head];
            m_head++;
            return node;
        }
    }


private:
    int m_max_size = 0;
    int m_head = 0;
    int m_tail = 0;
    ANode<T>** m_queue = nullptr;
};


#endif //QUEUE_ARRAYQUEUE_H
