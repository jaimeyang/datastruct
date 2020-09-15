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

const double E = 0.000001;

float Search::square(float value) {
//    auto mid = value;
//    auto low = 0;
//    auto hight = value;
//    while ( (hight - low) > 0.000001 ){
//        std::cout<<"mid is "<<mid<<std::endl;
//        mid = low + ( (hight - low) / 2 );
//        if ( (mid * mid) == value ){
//            return mid;
//        }else if( (mid * mid) > value ){
//            hight = mid;
//        }else{
//            low = mid;
//        }
//    }
//    return -1;
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
