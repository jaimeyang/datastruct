//
// Created by TestAdmin on 2020/9/15.
//

#ifndef SEARCH_SEARCH_H
#define SEARCH_SEARCH_H

#include <memory>

using namespace std;

class Search {
public:
    Search() = default;
    ~Search() = default;

public:
    int serach_binary(shared_ptr<int> data,int len,int value);
    float square(float value);
};


#endif //SEARCH_SEARCH_H
