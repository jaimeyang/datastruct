//
// Created by TestAdmin on 2020/9/18.
//

#include "SkipList.h"

SNode *SkipList::create_node(int value) {
    SNode* n = new SNode;
    n->data = value;
    n->forwards = new SkipList;
    return nullptr;
}
