//
// Created by jaime on 2020/8/17.
//

#ifndef LINKLIST_DOUBLELINK_H
#define LINKLIST_DOUBLELINK_H

template<typename T>
struct DNode{
    T   data;
    DNode<T>* next;
    DNode<T>* prev;
};

template<typename T>
class DoubleLink {
public:
    DoubleLink(){
        m_head = new DNode<T>;
        m_tail = new DNode<T>;
        m_head->prev = nullptr;
        m_head->next = m_tail;
        m_tail->prev = m_head;
        m_tail->next = nullptr;
    }

    DNode<T>* get_data(int index){
        if ( (index >= this->m_count) ){
            return nullptr;
        }
        auto i = 0;
        auto node = m_head->next;
        while ( i < index ){
            node = node->next;
            i++;
        }
        return node;
    }

    int insert(T data,int index){
        if (index < 0){
            return -1;
        }
        auto new_node = create_node(data);
        auto node = get_data(index);
        if ( node == nullptr ){
            node = m_tail;
        }
        auto prev_node = node->prev;
        new_node->prev = prev_node;
        new_node->next = node;
        node->prev = new_node;
        prev_node->next = new_node;
        this->m_count++;
        return 0;
    }

    int del(int index){
        auto node = get_data(index);
        if (node == nullptr){
            return -1;
        }
        auto prev_node = node->prev;
        prev_node->next = node->next;
        node->next->prev = prev_node;
        delete node;
        node = nullptr;
        this->m_count--;
        return 0;
    }

    ~DoubleLink(){

    }

private:
    DNode<T>* create_node(T data){
        DNode<T>* node = new DNode<T>();
        node->data = data;
        node->next = nullptr;
        node->prev = nullptr;
        return node;
    }
private:
    DNode<T>* m_head = nullptr;
    DNode<T>* m_tail = nullptr;
    int m_count = 0;
};


#endif //LINKLIST_DOUBLELINK_H
