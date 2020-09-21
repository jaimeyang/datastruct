//
// Created by TestAdmin on 2020/9/15.
//

#ifndef SEARCH_SEARCH_H
#define SEARCH_SEARCH_H

#include <memory>

using namespace std;

class Search {
public:
    Search() = default;
    ~Search() = default;

public:
    int serach_binary(shared_ptr<int> data,int len,int value);

    //todo 不够高效，继续使用二叉查找
 //第一个等于值的元素
    int search_binary_eq_first(shared_ptr<int> data,int len,int value);
//    最后一个等于值的元素
    int search_binary_eq_last(shared_ptr<int> data,int len,int value);
//    第一个大于等于给定值的元素
    int search_binary_gt_first(shared_ptr<int> data,int len,int value);
//    最后一个小于等于给定值的元素
    int search_binary_lt_last(shared_ptr<int> data,int len,int value);
    float square(float value);
};


#endif //SEARCH_SEARCH_H
