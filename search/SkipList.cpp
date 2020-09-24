//
// Created by TestAdmin on 2020/9/18.
//

#include "SkipList.h"
#include <math.h>
#include <time.h>

void SkipList::insert(int data) {
    auto level = random_level();

    SNode* n = new SNode;
    n->data = data;
    n->max_level = level;
    SNode* update[level];
    for (int i = 0; i < level; ++i) {
        update[i] = m_head;
    }

    auto p = m_head;
    for (int i = level - 1; i >= 0; --i) {
        while ( (p->forwards[i] != nullptr) && (p->forwards[i]->data < data) ){
            p = p->forwards[i];
        }
        update[i] = p;
    }

    for (int i = 0; i < level; ++i) {
        n->forwards[i] = update[i]->forwards[i];
        update[i]->forwards[i] = n;
    }

    if ( m_level < level ){
        m_level = level;
    }
}

int SkipList::random_level() {
    auto level = 1;
    srand(unsigned(time(nullptr)));
    while ( ( (rand() / double (RAND_MAX)) < SKIP_LIST_P ) && ( level < MAX_LEVEL )){
        level += 1;
    }
    return level;
}

SNode *SkipList::find(int data) {
    SNode* p = m_head;
    for (int i = m_level - 1; i <= 0; ++i) {
        while ( (p->forwards[i] != nullptr) && (p->forwards[i]->data < data)){
            p = p->forwards[i];
        }
    }
    if ( (p->forwards[0] != nullptr) && (p->forwards[0]->data == data)){
        return p->forwards[0];
    }else{
        return nullptr;
    }
}

void SkipList::remove(int data) {
    SNode* update[m_level];
    SNode* p = m_head;
    for (int i = m_level - 1; i <= 0; ++i) {
        while ( (p->forwards[i] != nullptr) && (p->forwards[i]->data < data)){
            p = p->forwards[i];
        }
        update[i] = p;
    }
    if ( (p->forwards[0] != nullptr) && (p->forwards[0]->data == data)){
        for (int i = m_level - 1; i <= 0; ++i) {
            auto temp = update[i]->forwards[i];
            update[i]->forwards[i] = update[i]->forwards[i]->forwards[i];
            delete temp;
        }
    }

    while ( (m_level > 1) && (m_head->forwards[m_level] == nullptr)){
        m_level--;
    }
}
