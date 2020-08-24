//
// Created by jaime on 2020/8/15.
//

#ifndef LINKLIST_CIRCLELINK_H
#define LINKLIST_CIRCLELINK_H

template<typename T>
struct CNode{
    T data;
    CNode<T>* next;
};

template<typename T>
class CircleLink {
public:
    CircleLink(){
        this->m_count = 0;
        m_link = new CNode<T>();
        m_link->next = m_link;
    }
    ~CircleLink(){

    }

public:

    CNode<T>* get_data(int index){
        if ( index > m_count ){
            index = index % m_count;
            index -= 1;
        }
        if ( index == -1 ){
            return m_link;
        }
        auto i = 0;
        auto node = m_link->next;
        while ( i < index ){
            node = node->next;
            i++;
        }
        return node;
    }

    //在index的位置插入
    int insert(T data,int index){
        auto node = create_node(data);
        auto p = m_link;
        auto i = 0;
        while ( i < index ){
            i++;
            p = p->next;
        }
        auto p1 = p->next;
        p->next = node;
        node->next = p1;
        this->m_count++;
        return 0;
    }


    //删除指定位置的节点 -1 不能删除头节点
    int del(int index){
        if (this->m_count <= 0){
            return -1;
        }
        auto node = get_data(index);
        auto p = node->next;
        node->next = p->next;
        delete p;
        p = nullptr;
        this->m_count--;
    }
private:
    CNode<T>* create_node(T data){
        CNode<T>* node = new CNode<T>();
        node->data = data;
        node->next = nullptr;
        return node;
    }
private:
    CNode<T>* m_link;
    int m_count;
};


#endif //LINKLIST_CIRCLELINK_H
