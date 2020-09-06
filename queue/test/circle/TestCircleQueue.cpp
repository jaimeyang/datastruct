//
// Created by jaime on 2020/9/6.
//
//
// Created by jaime on 2020/8/31.
//

//
// Created by jaime on 2020/8/28.
//

#include "gtest/gtest.h"
#include "../../CircleQueue.h"
#include <memory>
#include <future>


using namespace std;


class TestCircleQueue : public testing::Test{

public:
    void SetUp(){
        m_queue = make_unique<CircleQueue<char*>>(10);
    }

    void TearDown(){

    }

public:
    unique_ptr<CircleQueue<char*>> m_queue;
};

TEST_F(TestCircleQueue,test_circle_queue){
    char* s = "";
    GTEST_ASSERT_EQ(false,m_queue.get()->dequeue(s));

    m_queue.get()->enqueue("10");
    char* d1 = "";
    m_queue.get()->dequeue(d1);
    GTEST_ASSERT_EQ("10",d1);

    for (int i = 10; i < 20; ++i) {
        char* s = new char[2];
        sprintf(s,"%d",i);
        GTEST_ASSERT_EQ(true,m_queue.get()->enqueue(s));
    }
    GTEST_ASSERT_EQ(false,m_queue.get()->enqueue("22"));
//
    char* d2 = "";
    m_queue.get()->dequeue(d2);
    char* t1 = "10";
    GTEST_ASSERT_EQ(*d2,*t1);
}
