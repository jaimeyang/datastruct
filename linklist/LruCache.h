//
// Created by jaime on 2020/8/24.
//

#ifndef LINKLIST_LRUCACHE_H
#define LINKLIST_LRUCACHE_H

#include "SingleLink.h"
#include <memory>

using namespace std;
class LruCache {
public:
    LruCache(unsigned int size):
            m_max_size(size){
        m_link = make_unique<SingleLink<int>>();
    }
    ~LruCache(){

    }

public:
    void put_in_cache(int data);
    int get_in_cache(int index){
        return m_link.get()->get_data(index)->data;
    }
private:
    unique_ptr<SingleLink<int>> m_link;
    unsigned int m_size = 0;
    unsigned int m_max_size = 0;
};


#endif //LINKLIST_LRUCACHE_H
