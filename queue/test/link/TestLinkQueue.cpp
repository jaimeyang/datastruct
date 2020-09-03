//
// Created by jaime on 2020/8/31.
//

//
// Created by jaime on 2020/8/28.
//

#include "gtest/gtest.h"
#include "../../LinkQueue.h"
#include <memory>


using namespace std;


class TestLinkQueue : public testing::Test{

public:
    void SetUp(){
        m_queue = make_unique<LinkQueue<int>>(10);
    }

    void TearDown(){

    }

public:
    unique_ptr<LinkQueue<int>> m_queue;
};

TEST_F(TestLinkQueue,test_array_queue){

}