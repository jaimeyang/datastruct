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
//    sort select
    unique_ptr<int> sort_select(unique_ptr<int> data,int len);
    //todo improvement the alghrothm of direct bable
    unique_ptr<int> sort_bable_2(unique_ptr<int> data,int len);
    //sort merge
    void sort_merge(shared_ptr<int> data,int len);
    //sort quick
    void sourt_quick(shared_ptr<int> data,int len);
private:
    void merge_recurision(shared_ptr<int> data,int begin,int end);
    void merge(shared_ptr<int> dst,int begin,int middle,int end);

    void quick_recurision(shared_ptr<int> data,int begin,int end);
    int partion(shared_ptr<int> data,int begin,int end);
    void swap(shared_ptr<int> data,int pre,int next);
};


#endif //SORT_SORT_H
