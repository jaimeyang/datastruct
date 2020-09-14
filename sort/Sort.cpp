//
// Created by jaime on 2020/9/7.
//

#include <iostream>
#include "Sort.h"

unique_ptr<int> Sort::sort_direct(unique_ptr<int> data, int len) {
    for (int i = 1; i < len; ++i) {
        auto value = data.get()[i];
        auto j = i - 1;
        for ( j; j >= 0; j--){
            if ( value < data.get()[j]){
                data.get()[j+1] = data.get()[j];
            }else{
                break;
            }
        }
        data.get()[j+1] = value;
    }
    return std::move(data);
}

unique_ptr<int> Sort::sort_bable(unique_ptr<int> data, int len) {
    if ( len <= 1){
        return std::move(data);
    }
    for (int i = 0; i < len; ++i) {
        auto flag = false;
        for (int j = 0; j < len - i - 1; j++){
            if (data.get()[j] > data.get()[j + 1]){
                int temp = data.get()[j];
                data.get()[j] = data.get()[j + 1];
                data.get()[j + 1] = temp;
                flag = true;
            }
        }
        if ( !flag ){
            break;
        }
    }
    return std::move(data);
}

unique_ptr<int> Sort::sort_select(unique_ptr<int> data, int len) {
    for (int i = 0; i < len; ++i) {
        int minIndex = i;
        for (int j = i + 1; j < len; ++j) {
            if ( data.get()[j] < data.get()[minIndex]){
                minIndex = j;
            }
        }
        int temp = data.get()[i];
        data.get()[i] = data.get()[minIndex];
        data.get()[minIndex] = temp;
    }
    return std::move(data);
}


unique_ptr<int> Sort::sort_bable_2(unique_ptr<int> data, int len) {
    if ( len <= 1){
        return std::move(data);
    }
    auto sort_border = len - 1;
    auto last_change = 0;
    for (int i = 0; i < len; ++i) {
        auto flag = false;
        for (int j = 0; j < sort_border; j++){
            if (data.get()[j] > data.get()[j + 1]){
                int temp = data.get()[j];
                data.get()[j] = data.get()[j + 1];
                data.get()[j + 1] = temp;
                flag = true;
                last_change = j;
            }
        }
        sort_border = last_change;
        if ( !flag ){
            break;
        }
    }
    return std::move(data);
}

//根据有序数组合并的性质，进行递归排序
void Sort::sort_merge(shared_ptr<int> data, int len) {
    merge_recurision(data,0,len -1 );
}

void Sort::merge_recurision(shared_ptr<int> data, int begin, int end) {
    if (begin >= end){
        return;
    }
    int midle = (begin + end) / 2;
    merge_recurision(data,begin,midle);
    merge_recurision(data,midle + 1,end);
    merge(data,begin,midle,end);
}

void Sort::merge(shared_ptr<int> dst, int begin, int middle, int end) {
    std::cout<<"merge begin "<<begin<<" middle "<<middle<<" end "<<end<<std::endl;
    for (int i1 = begin; i1 <= end; ++i1) {
        std::cout<<"i1 is "<<dst.get()[i1]<<std::endl;
    }
    auto len = end - begin + 1;
    int a[len];
    auto i = begin;
    auto j = middle + 1;
    auto k = 0;
    while ( (i <= middle) && (j <= end) ){
        if ( dst.get()[i] <= dst.get()[j]){
            a[k] = dst.get()[i];
            i++;
        }else{
            a[k] = dst.get()[j];
            j++;
        }
        k++;
    }

    auto remain_start = i;
    auto remain_end = middle;
    if ( j <= end ){
        remain_start = j;
        remain_end = end;
    }

    std::cout<<"remain "<<remain_start<<" remain_end "<<remain_end<<std::endl;
    for (int l = remain_start; l <= remain_end; ++l) {
        a[k] = dst.get()[l];
        k++;
    }

    auto n = 0;
    for (int m = begin; m <= end; ++m) {
        dst.get()[m] = a[n];
        std::cout<<"m is "<<m<<", "<<a[n]<<std::endl;
        n++;
    }
}

void Sort::sourt_quick(shared_ptr<int> data, int len) {
    quick_recurision(data,0,len - 1);
}

void Sort::quick_recurision(shared_ptr<int> data, int begin, int end) {
    if ( begin >= end ){
        return;
    }
    int p = partion(data,begin,end);
    quick_recurision(data,begin,p - 1);
    quick_recurision(data,p + 1,end);
}

int Sort::partion(shared_ptr<int> data, int begin, int end) {
    auto pivot = data.get()[end];
    auto i = begin;
    for (int j = begin; j < end; ++j) {
        if ( data.get()[j] < pivot ){
            swap(data,i,j);
            i++;
        }
    }
    swap(data,i,end);
    return i;
}

void Sort::swap(shared_ptr<int> data, int pre, int next) {
    auto temp = data.get()[pre];
    data.get()[pre] = data.get()[next];
    data.get()[next] = temp;
}
