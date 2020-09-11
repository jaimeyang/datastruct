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

void Sort::sort_merge(shared_ptr<int> data, int len) {
    merge_recurision(data,0,len);
}

void Sort::merge_recurision(shared_ptr<int> data, int begin, int end) {
    std::cout<<"begin "<<begin<<std::endl;
    std::cout<<"end "<<end<<std::endl;
    if (begin >= end){
        return;
    }
    int midle = (begin + end) / 2;
    merge_recurision(data,begin,midle);
    std::cout<<"left "<<begin<<", "<<data.get()[begin]<<std::endl;
    merge_recurision(data,midle + 1,end);
    std::cout<<"right "<<midle + 1<<", "<<data.get()[midle + 1]<<std::endl;
    merge(data,begin,midle,end);
    std::cout<<"begin "<<begin<<", "<<data.get()[begin]<<std::endl;
}

void Sort::merge(shared_ptr<int> dst, int begin, int middle, int end) {
    auto len = end - begin;
    int a[len];
    auto i = begin;
    auto j = middle;
    auto k = 0;
    while ( (i < middle) && (j < end) ){
        if ( dst.get()[i] < dst.get()[j]){
            a[k] = dst.get()[i];
            i++;
        }else{
            a[k] = dst.get()[j];
            j++;
        }
        k++;
    }

    for (int i1 = 0; i1 < (k-1); ++i1) {
        std::cout<<"a[k] "<<i1<<", "<<a[i1]<<std::endl;
    }

    auto remain = 0;
    auto remain_end = 0;
    if ( i < middle ){
        remain = middle - i;
        remain_end = middle;
    }else{
        remain = end - j;
        remain_end = end;
    }
    for (int l = remain; l < remain_end; ++l) {
        a[k] = dst.get()[l];
        k++;
    }

    auto n = 0;
    for (int m = begin; m < end; ++m) {
        dst.get()[m] = a[n];
        std::cout<<"circle "<<begin<<", "<<a[n]<<std::endl;
        n++;
    }
}
