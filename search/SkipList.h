//
// Created by TestAdmin on 2020/9/18.
//

#ifndef SEARCH_SKIPLIST_H
#define SEARCH_SKIPLIST_H

const int MAX_LEVEL = 16;
const int SKIP_LIST_P = 0.5;

typedef struct SNode {
    int max_level = 0;
    int data = -1;
    SNode* forwards[MAX_LEVEL];
};


class SkipList {
public:
    SkipList() = default;
    ~SkipList() = default;

public:
    void insert(int data);
    void find()
private:
    SNode* create_node(int value);
};


#endif //SEARCH_SKIPLIST_H
