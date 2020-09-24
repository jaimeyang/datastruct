//
// Created by TestAdmin on 2020/9/18.
//

#ifndef SEARCH_SKIPLIST_H
#define SEARCH_SKIPLIST_H

#include "iostream"

const int MAX_LEVEL = 16;
const int SKIP_LIST_P = 0.5;

typedef struct SNode {
    int max_level = 0;
    int data = -1;
    SNode* forwards[MAX_LEVEL];
};


using namespace std;

class SkipList {
public:
    SkipList(){
        m_head = new SNode();
        m_head->data = -1;
        for (int i = 0; i < MAX_LEVEL; ++i) {
            m_head->forwards[i] = nullptr;
        }
        m_level = 1;
    };
    ~SkipList() = default;

public:
    void insert(int data);
    SNode* find(int data);
    void remove(int data);
private:
    // 理论来讲，一级索引中元素个数应该占原始数据的 50%，二级索引中元素个数占 25%，三级索引12.5% ，一直到最顶层。
    // 因为这里每一层的晋升概率是 50%。对于每一个新插入的节点，都需要调用 randomLevel 生成一个合理的层数。
    // 该 randomLevel 方法会随机生成 1~MAX_LEVEL 之间的数，且 ：
    //        50%的概率返回 1
    //        25%的概率返回 2
    //      12.5%的概率返回 3 ...
    int random_level();
    SNode* create_node(int value);
    SNode* m_head = nullptr;
    int m_level = 1;
};


#endif //SEARCH_SKIPLIST_H
