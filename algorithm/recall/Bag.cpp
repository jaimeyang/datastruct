//
// Created by jaime on 2021/2/20.
//

#include "Bag.h"

int Bag::recall(int cw, const vector<int> &item, int count,int max_w) {
    if ( cw > max_w || count > item.size() - 1) {
        return cw;
    }
    //搜索减枝
    recall(cw,item,count + 1,max_w);
    if (cw + item.at(count) < max_w) {
        return recall(cw + item.at(count),item,count + 1,max_w);
    }
    return cw;
}
