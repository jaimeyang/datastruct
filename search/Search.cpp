//
// Created by TestAdmin on 2020/9/15.
//

#include <iostream>
#include "Search.h"

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

float Search::square(float value) {
    auto mid = value;
    auto low = 0;
    auto hight = value;
    while ( (hight - low) > 0.000001 ){
        mid = low + ((low - hight) / 2);
        if ( (mid * mid) == value ){
            return mid;
        }else if( (mid * mid) > value ){
            hight = mid;
        }else{
            low = mid;
        }
    }
    return -1;
}
