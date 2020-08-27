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
        m_stack = new LNode<T>();
        m_stack->next = nullptr;
    }
    ~LinkStack(){

    }

public:
    int push(T data){
        if ( m_count >= m_max_size ){
            return -1;
        }else{
            LNode<T>* node = new LNode<T>();
            node->data = data;
            node->next = m_stack->next;
            m_stack->next = node;
            this->m_count++;
            return -1;
        }

    }

    LNode<T>* top(){
        if ( m_count == 0 ){
            return nullptr;
        }else{
            return m_stack->next;
        }
    }

    int pop(){
        if ( m_count <= 0 ){
            return -1;
        }else{
            auto node = m_stack->next;
            m_stack->next = node->next;
            this->m_count--;
            delete node;
            node = nullptr;
            return 0;
        }

    }
private:
    LNode<T>* m_stack = nullptr;
    int m_max_size = 0;
    int m_count = 0;
};


#endif //STACK_LINKSTACK_H
