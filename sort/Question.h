//
// Created by jaime on 2020/9/15.
//

#ifndef SORT_QUESTION_H
#define SORT_QUESTION_H

#include <memory>

using namespace std;

class Question {
public:
    Question() = default;
    ~Question() = default;

public:
    int k_max_select(shared_ptr<int> data,int len,int k);

private:
    int k_max_recurision(shared_ptr<int> data,int begin,int end,int k);
    int k_max_partion(shared_ptr<int> data,int begin,int end);
    void swap(shared_ptr<int> data,int pre,int next);
};


#endif //SORT_QUESTION_H
