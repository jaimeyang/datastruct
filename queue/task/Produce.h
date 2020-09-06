//
// Created by jaime on 2020/9/6.
//

#ifndef QUEUE_PRODUCE_H
#define QUEUE_PRODUCE_H

#include "Comsumer.h"

const int NUM_COMSUMER = 4;

class Produce {
public:
    Produce(){
        m_coumsumer = new Comsumer*[NUM_COMSUMER];
    };
    ~Produce();

public:
    void add_comsumer(Comsumer* c);
    void produce(int n);

private:
    Comsumer** m_coumsumer = nullptr;
    int m_count = 0;
    int m_last = 0;
};


#endif //QUEUE_PRODUCE_H
