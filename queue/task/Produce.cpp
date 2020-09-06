//
// Created by jaime on 2020/9/6.
//

#include <iostream>
#include "Produce.h"

void Produce::produce(int n) {
    for (int i = 0; i < n; ++i) {
        while ( !(m_coumsumer[m_last]->put_task(i)) ){
            m_last = (m_last + 1) % m_count;
//            std::cout<<"data is "<<i<<std::endl;
        }
    }
}

void Produce::add_comsumer(Comsumer *c) {
    if ( m_count >= NUM_COMSUMER ){
        return;
    }
    m_coumsumer[m_count] = c;
    m_count++;
}
