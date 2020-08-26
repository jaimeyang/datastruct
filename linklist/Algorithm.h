//
// Created by jaime on 2020/8/18.
//

#ifndef LINKLIST_ALGORITHM_H
#define LINKLIST_ALGORITHM_H


#include "SingleLink.h"
#include <memory>

using namespace std;

using slink_char_uptr = unique_ptr<SingleLink<char>>;
using slink_char_sptr = shared_ptr<SingleLink<char>>;

using slink_int_uptr = unique_ptr<SingleLink<int>>;

class Algorithm {
public:
    Algorithm(){
        m_slink = make_unique<SingleLink<char>>();
    }
private:
public:
    //判断字符串是不是回文字符串
    bool is_palindrome(slink_char_uptr data);
    //单链表反转
    void reverse(slink_char_sptr data);
    //单练表环的检测
    bool isCircle(slink_char_sptr list);
    //链表合并
    slink_int_uptr merge(slink_int_uptr one,slink_int_uptr two);
private:
    unique_ptr<SingleLink<char>> m_slink;
};


#endif //LINKLIST_ALGORITHM_H
