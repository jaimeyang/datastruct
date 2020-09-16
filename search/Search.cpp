//
// Created by TestAdmin on 2020/9/15.
//

#include <iostream>
#include "Search.h"
#include "x.h"

int Search::serach_binary(shared_ptr<int> data,int len, int value) {
    auto mid = 0;
    auto low = 0;
    auto hight = len - 1;
    while ( low <= hight ){
        mid = low + ((hight - low) >> 1);
        if ( data.get()[mid] == value ){
            return mid;
        }else if( data.get()[mid] < value ){
            low = mid + 1;
        }else{
            hight = mid - 1;
        }
    }
    return -1;
}

const double E = 0.000001;

float Search::square(float value) {
    auto start = 1.0;
    auto end = value;
    auto mid = 0.0;
    while (1){
        mid = (start + end) / 2;
        if ( ((mid * mid - value) <= E) && (((mid * mid) - value) >= (-E))){
            return mid;
        }
        if ( (mid * mid - value) > E ){
            end = mid;
        }else{
            start = mid;
        }
    }
    return 0;
}

int Search::search_binary_eq_first(shared_ptr<int> data, int len, int value) {
    auto mid = 0;
    auto low = 0;
    auto hight = len - 1;
    while ( low <= hight ){
        mid = low + ((hight - low) >> 1);
        if ( data.get()[mid] == value ){
            for (int i = mid; i >= 0; --i) {
                if ( data.get()[i] < value){
                    return i + 1;
                }
            }
        }else if( data.get()[mid] < value ){
            low = mid + 1;
        }else{
            hight = mid - 1;
        }
    }
    return -1;
}

int Search::search_binary_eq_last(shared_ptr<int> data, int len, int value) {
    auto mid = 0;
    auto low = 0;
    auto hight = len - 1;
    while ( low <= hight ){
        mid = low + ((hight - low) >> 1);
        if ( data.get()[mid] == value ){
            for (int i = mid; i < len; ++i) {
                if ( data.get()[i] > value){
                    return i - 1;
                }
            }
        }else if( data.get()[mid] < value ){
            low = mid + 1;
        }else{
            hight = mid - 1;
        }
    }
    return -1;
}

int Search::search_binary_gt_first(shared_ptr<int> data, int len, int value) {
    auto mid = 0;
    auto low = 0;
    auto hight = len - 1;
    while ( low <= hight ){
        mid = low + ((hight - low) >> 1);
        if ( data.get()[mid] == value ){
            for (int i = mid; i >= 0; --i) {
                if ( data.get()[i] < value){
                    return i + 1;
                }
            }
        }else if( data.get()[mid] < value ){
            low = mid + 1;
        }else{
            hight = mid - 1;
        }
    }
    return low;
}

int Search::search_binary_lt_last(shared_ptr<int> data, int len, int value) {
    auto mid = 0;
    auto low = 0;
    auto hight = len - 1;
    while ( low <= hight ){
        mid = low + ((hight - low) >> 1);
        if ( data.get()[mid] == value ){
            for (int i = mid; i < len; ++i) {
                if ( data.get()[i] > value){
                    return i - 1;
                }
            }
        }else if( data.get()[mid] < value ){
            low = mid + 1;
        }else{
            hight = mid - 1;
        }
    }
    return hight;
}
