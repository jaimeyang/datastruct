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
