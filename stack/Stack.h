//
// Created by jaime on 2020/8/26.
//

#ifndef STACK_STACK_H
#define STACK_STACK_H

template<typename T>
struct Node{
    T   data;
};


template<typename T>
class Stack {
public:
    Stack(int size):
    m_max_size(size),m_stack(new Node<T>*[m_max_size]){

    }
    ~Stack(){

    }

public:
    //-1 满了 0成功
    int push(T data){
        if ( m_cur >= m_max_size){
            return -1;
        }else{
            Node<T>* node = new Node<T>();
            node->data = data;
            m_stack[m_cur] = node;
            m_cur++;
        }
    }

    Node<T>* top(){
        if ( m_cur == 0 ){
            return nullptr;
        }
        return m_stack[m_cur - 1];
    }

    int pop(){
        if ( m_cur == 0 ){
            return -1;
        } else{
            Node<T>* node = m_stack[m_cur-1];
            m_cur--;
            delete node;
            node = nullptr;
            return 0;
        }

    }
private:
    int m_max_size = 0;
    int m_cur = 0;
    Node<T>**  m_stack = nullptr;
};


#endif //STACK_STACK_H
