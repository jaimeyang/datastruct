//
// Created by jaime on 2020/8/18.
//

#include <cstring>
#include "Algorithm.h"

//空字符串也是回文字符串 区分大小写
bool Algorithm::is_palindrome(slink_char_uptr data) {
    auto len = data.get()->size();
    char p1[len],p2[len];
    for (int i = 0; i < len; ++i) {
        p1[i] = data.get()->get_data(i)->data;
        p2[i] = data.get()->get_data(i)->data;
    }
    unsigned int k = 0;
    unsigned int j = len - 1;
    while ( k < len ){
        if (p1[k] != p2[j]){
            return false;
        }
        k++;
        j--;
    }
    return true;
}

void Algorithm::reverse(slink_char_sptr data) {
    auto head = data.get()->get_head();
    auto curr = data.get()->get_data(0);
    SNode<char>* prev = nullptr;
    auto next = curr->next;
    while ( next != nullptr ){
        curr->next = prev;
        prev = curr;
        curr = next;
        next = curr->next;
    }
    curr->next = prev;
    head->next = curr;
    return;
}

bool Algorithm::isCircle(slink_char_sptr list) {
    auto fast = list.get()->get_head();
    auto slow = list.get()->get_head();
    while ( fast->next != nullptr ){
        slow = slow->next;
        fast = fast->next->next;
        if (fast == slow){
            return true;
        }
    }
    return false;
}
//todo 更符合面先对象的做法是 添加一个迭代类 去掉友元类
slink_int_uptr Algorithm::merge(slink_int_uptr one, slink_int_uptr two) {
    auto p1 = one.get()->get_head();
    auto p2 = two.get()->get_head();
    while ( (p2->next != nullptr) && (p1->next != nullptr) ){
        int d1 = p1->next->data;
        int d2 = p2->next->data;
        if ( d1 >= d2 ){
            auto temp = p2->next;
            p2->next = temp->next;
            temp->next = p1->next;
            p1->next = temp;
            one.get()->m_count++;
        }else{
            p1 = p1->next;
        }
    }
    if ( p2->next != nullptr ){
        p1->next = p2->next;
        auto i = 0;
        while (p2->next != nullptr){
            one.get()->m_count++;
            p2 = p2->next;
        }
    }
    return std::move(one);
}
