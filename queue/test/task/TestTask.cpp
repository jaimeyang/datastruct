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

TEST_F(TestTask,test_task){
    auto sum = 0;
    for ( int i = 0; i < 1000;i++){
        sum += i;
    }


    Comsumer* c = new Comsumer();
    Produce* p = new Produce();
    p->add_comsumer(c);

    std::async(std::launch::async,&Comsumer::comsume,c);
    std::async(std::launch::async,&Produce::produce,p,1000);

    sleep(10);
    GTEST_ASSERT_EQ(sum,c->get_sum());
}