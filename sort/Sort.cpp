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
    for (int i = 0; i < (len - 1); ++i) {
        auto j = i + 1;
        auto flag = false;
        for (j; j > 0; j--){
            if (data.get()[j] < data.get()[j - 1]){
                int temp = data.get()[j];
                data.get()[j] = data.get()[j - 1];
                data.get()[j - 1] = temp;
                flag = true;
            }
            if ( !flag ){
                break;
            }
        }
    }
    return std::move(data);
}
