//
// Created by jaime on 2020/9/15.
//

#include <iostream>
#include "Question.h"

int Question::k_max_select(shared_ptr<int> data, int len, int k) {
    auto result = k_max_recurision(data,0,len - 1,k);
    return result;
}

int Question::k_max_recurision(shared_ptr<int> data, int begin, int end,int k) {
    if (begin >= end){
        return data.get()[0];
    }
    auto result = 0;
    auto p = k_max_partion(data,begin,end);
    if ( (p + 1) == k ){
        return data.get()[p];
    }else if ( (p + 1) < k ){
        result = k_max_recurision(data,p + 1,end,k);
    }else{
        result = k_max_recurision(data,begin,p - 1,k);
    }
    return result;
}

int Question::k_max_partion(shared_ptr<int> data, int begin, int end) {
    auto pivot = data.get()[end];

    auto i = begin;
    for (int j = 0; j < end; ++j) {
        if ( data.get()[j] > pivot ){
            swap(data,i,j);
            i++;
        }
    }
    swap(data,i,end);
    return i;
}


void Question::swap(shared_ptr<int> data, int pre, int next) {
    auto temp = data.get()[pre];
    data.get()[pre] = data.get()[next];
    data.get()[next] = temp;
}