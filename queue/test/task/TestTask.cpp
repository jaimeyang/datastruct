//
// Created by jaime on 2020/9/6.
//

#include <gtest/gtest.h>
#include <future>
#include "../../task/Produce.h"

class TestTask : public testing::Test{

public:
    void SetUp(){
    }

    void TearDown(){

    }

public:
};

void* p_comsuer(void* data){
    Comsumer* c = (Comsumer*)data;
    c->comsume();
}

void* p_prodcuer(void* data){
    Produce* p = (Produce*)data;
    p->produce(1000);
}

TEST_F(TestTask,test_task){
    auto sum = 0;
    for ( int i = 0; i < 1000;i++){
        sum += i;
    }


    Comsumer* c = new Comsumer();
    Produce* p = new Produce();
    p->add_comsumer(c);
    //todo 不添加返回值就不会启动新线程
//    auto f1 = std::async(std::launch::async,&Comsumer::comsume,c);
//    auto f2 = std::async(std::launch::async,&Produce::produce,p,1000);
    pthread_t t1;
    pthread_create(&t1, nullptr,p_comsuer, c);
    pthread_detach(t1);

    pthread_t t2;
    pthread_create(&t2, nullptr,p_prodcuer,p);
    pthread_detach(t2);

    sleep(5);
    GTEST_ASSERT_EQ(sum,c->get_sum());
}