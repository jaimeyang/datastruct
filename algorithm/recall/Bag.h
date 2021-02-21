//
// Created by jaime on 2021/2/20.
//0-1背包问题
//

#ifndef ALGORITHM_BAG_H
#define ALGORITHM_BAG_H

#include <vector>

using namespace std;

class Bag {
public:
    Bag() {

    }
    ~Bag(){

    }
    //回溯法解决,数据已经排好序
    //cw 现在的重量
    //item 物品
    //count 考察到第几个物品
    //max_w 最大的重量
    //max_ew 期望的最大的重量
    //返回期望的最大的重量
    int recall(int cw,const vector<int>& item,int count,int max_w);

private:

};


#endif //ALGORITHM_BAG_H
