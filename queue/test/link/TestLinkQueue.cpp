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

TEST_F(TestLinkQueue,test_link_queue){
    int d0 = 0;
    GTEST_ASSERT_EQ(false,m_queue.get()->dequeue(d0));

    m_queue.get()->enqueue(10);
    auto d1 = 0;
    m_queue.get()->dequeue(d1);
    GTEST_ASSERT_EQ(10,d1);
//
    for (int i = 0; i < 10; ++i) {
        m_queue.get()->enqueue(i);
    }
    GTEST_ASSERT_EQ(-1,m_queue.get()->enqueue(1));

    auto d2 = -1;
    m_queue.get()->dequeue(d2);
    GTEST_ASSERT_EQ(0,d2);
    auto d3 = 0;
    m_queue.get()->dequeue(d3);
    GTEST_ASSERT_EQ(1,d3);
}