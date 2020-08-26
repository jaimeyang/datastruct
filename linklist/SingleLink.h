//
// Created by jaime on 2020/8/13.
//

#ifndef LINKLIST_SINGLELINK_H
#define LINKLIST_SINGLELINK_H

#include <memory>

class Algorithm;

using namespace std;
template<typename T>
struct SNode{
    T   data;
    SNode*  next;
};

//todo 实现了核心的插入删除操作，后续添加销毁全部节点，从尾部插入，尾部删除操作
template<typename T>
class SingleLink {
public:
    SingleLink():
    m_link(new SNode<T>()){
        m_link->next = nullptr;
    };
    ~SingleLink(){
        delete m_link;
        m_link = nullptr;
    };

    SNode<T>* get_head(){
        return this->m_link;
    }


    void push_back(T data){
        insert(data,this->m_count);
    }

    void pop_back(){
        del(this->m_count);
    }

    int size(){
        return this->m_count;
    }

    //在index的位置插入
    int insert(T data,int index){
        if ( index < 0 ){
            return -1;
        }
        auto node = create_node(data);
        if ( node->next != nullptr ){
            return -1;
        }
        auto p = m_link;
        auto i = 0;
        while ( (i < index) && (p->next != nullptr) ){
            i++;
            p = p->next;
        }
        auto p1 = p->next;
        p->next = node;
        node->next = p1;
        this->m_count++;
        return 0;
    }

    SNode<T>* get_data(int index){
        if ( (index > this->m_count) ){
            return nullptr;
        }
        if ( index < 0 ){
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
    //删除指定位置的节点 -1 超出范围
    int del(int index){
        if ( index >= this->m_count ){
            return -1;
        }
        auto node = get_data(index - 1);
        auto p = node->next;
        node->next = p->next;
        delete p;
        p = nullptr;
        this->m_count--;
        return 0;
    }

    void del_reciprocal(int n){
        auto fast = get_head();
        auto slow = get_head();
        if (fast->next == nullptr || (fast->next->next == nullptr)){
            return;
        }
        auto size = 0;
        while ( fast->next != nullptr ){
            fast = fast->next;
            size++;
        }
        auto pos = size - n;
        for (int i = 0; i < pos; ++i) {
            slow = slow->next;
        }
        auto temp = slow->next;
        slow->next = temp->next;
        delete temp;
        temp = nullptr;
        this->m_count--;
    }
public:
    void traverse();

private:
    SNode<T>* create_node(T data){
        SNode<T>* node = new SNode<T>();
        node->data = data;
        node->next = nullptr;
        return node;
    }
private:
    friend class Algorithm;
    SNode<T>* m_link = nullptr;
    SNode<T>* m_iter = nullptr;
    int m_count = 0;
};


#endif //LINKLIST_SINGLELINK_H
