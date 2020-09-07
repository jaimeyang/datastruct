//
// Created by jaime on 2020/9/7.
//

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