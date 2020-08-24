//
// Created by jaime on 2020/8/24.
//

#include "LruCache.h"

void LruCache::put_in_cache(int data) {
    auto list = m_link.get()->get_head();
    SNode<int>* prev_node = nullptr;
    while (list->next != nullptr){
        if ( list->next->data == data ){
            prev_node = list;
            break;
        }
        list = list->next;
    }
    //存在，插入到最前面
    if ( (prev_node != nullptr ) && (prev_node->next != nullptr) ){
        auto head = m_link.get()->get_head();
        auto node = prev_node->next;
        head->next = node;
        prev_node->next = node->next;
    }else{
        if ( m_size == m_max_size ){
            m_link.get()->pop_back();
            m_link.get()->insert(data,0);
        }else{
            m_link.get()->insert(data,0);
            m_size += 1;
        }
    }
}
