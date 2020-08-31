//
// Created by jaime on 2020/8/28.
//

#include "gtest/gtest.h"
#include "../../ArrayQueue.h"
#include <memory>


using namespace std;


class TestArrayQueue : public testing::Test{

public:
    void SetUp(){
        m_queue = make_unique<ArrayQueue<int>>(10);
    }

    void TearDown(){

    }

public:
    unique_ptr<ArrayQueue<int>> m_queue;
};

TEST_F(TestArrayQueue,test_array_queue){
    GTEST_ASSERT_EQ(nullptr,m_queue.get()->dequeue());

    m_queue.get()->enqueu(10);
    GTEST_ASSERT_EQ(10,m_queue.get()->dequeue()->data);

    for (int i = 0; i < 10; ++i) {
        m_queue.get()->enqueu(i);
    }
    GTEST_ASSERT_EQ(-1,m_queue.get()->enqueu(1));

    GTEST_ASSERT_EQ(0,m_queue.get()->dequeue()->data);
    GTEST_ASSERT_EQ(1,m_queue.get()->dequeue()->data);
}