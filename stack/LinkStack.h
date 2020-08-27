//
// Created by jaime on 2020/8/27.
//

#ifndef STACK_LINKSTACK_H
#define STACK_LINKSTACK_H

template<typename T>
struct LNode{
    T   data;
    LNode<T>*   next;
};

template<typename T>
class LinkStack {
public:
    LinkStack(int size):
    m_max_size(size){

    }
    ~LinkStack(){

    }

public:
    int push(T data){
        LNode<T>* node = new LNode<T>();
        node->data = data;
        if ( m_cur == nullptr ){
            m_cur = node;
        }
    }

    LNode<T>* top(){

    }

    int pop(){

    }
private:
    LNode<T>* m_cur = nullptr;
    int m_max_size = 0;
};


#endif //STACK_LINKSTACK_H
