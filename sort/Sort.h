//
// Created by jaime on 2020/9/7.
//

#ifndef SORT_SORT_H
#define SORT_SORT_H

#include <memory>

using namespace std;

class Sort {
public:
    Sort() = default;
    ~Sort() = default;

public:
//    sort direct
    unique_ptr<int> sort_direct(unique_ptr<int> data,int len);
// sort bable
    unique_ptr<int> sort_bable(unique_ptr<int> data,int len);
private:
};


#endif //SORT_SORT_H
