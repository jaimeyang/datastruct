//
// Created by jaime on 2020/8/13.
//


#include <gtest/gtest.h>
#include <memory>
#include "../../SingleLink.h"

using namespace std;

class TestSingle : public ::testing::Test{
public:
    TestSingle(){

    }
    ~TestSingle(){

    }

    void SetUp(){
        m_link = make_unique<SingleLink<int>>();
    }

    void TearDown(){

    }

    unique_ptr<SingleLink<int>> m_link;
};


TEST_F(TestSingle,test_insert){
    GTEST_ASSERT_EQ(m_link.get()->insert(1,-1),-1);

    GTEST_ASSERT_EQ(m_link.get()->insert(1,6),0);
    GTEST_ASSERT_EQ(1,m_link.get()->get_data(0)->data);

//
    GTEST_ASSERT_EQ(0,m_link.get()->insert(2,1));
    auto d2 = m_link->get_data(1)->data;
    GTEST_ASSERT_EQ(d2,2);
//
    GTEST_ASSERT_EQ(0,m_link.get()->insert(5,1));
    auto d3 = m_link->get_data(1)->data;
    GTEST_ASSERT_EQ(d3,5);
//
    GTEST_ASSERT_EQ(0,m_link.get()->insert(15,0));
    auto d4 = m_link->get_data(0)->data;
    GTEST_ASSERT_EQ(d4,15);
}


TEST_F(TestSingle,test_del){
    for (int i = 0; i < 10; ++i) {
        m_link.get()->insert(i,i);
    }

    int d1 = m_link.get()->del(20);
    GTEST_ASSERT_EQ(-1,d1);

    int d2 = m_link.get()->del(10);
    GTEST_ASSERT_EQ(-1,d2);

    int d3 = m_link.get()->del(9);
    GTEST_ASSERT_EQ(0,d3);
    auto g1 = m_link.get()->get_data(9);
    GTEST_ASSERT_EQ(g1, nullptr);

    int d4 = m_link.get()->del(5);
    GTEST_ASSERT_EQ(0,d4);
    auto g2 = m_link.get()->get_data(5);
    GTEST_ASSERT_EQ(g2->data, 6);

    int d5 = m_link.get()->del(0);
    GTEST_ASSERT_EQ(0,d5);
    auto g3 = m_link.get()->get_data(0);
    GTEST_ASSERT_EQ(g3->data, 1);
}

TEST_F(TestSingle,test_push_back){
    for (int i = 0; i < 10; ++i) {
        m_link.get()->push_back(i);
    }
    for (int j = 0; j < 10; ++j) {
        GTEST_ASSERT_EQ(j,m_link.get()->get_data(j)->data);
    }

}

TEST_F(TestSingle,test_pop_back){
    for (int i = 0; i < 10; ++i) {
        m_link.get()->push_back(i);
    }
    m_link.get()->pop_back();
    GTEST_ASSERT_EQ(9,m_link.get()->get_data(9)->data);

}

TEST_F(TestSingle,test_del_reciprocal){
    for (int i = 0; i < 10; ++i) {
        m_link.get()->push_back(i);
    }
    m_link.get()->del_reciprocal(1);
    GTEST_ASSERT_EQ(8,m_link.get()->get_data(8)->data);
    m_link.get()->del_reciprocal(2);
    GTEST_ASSERT_EQ(6,m_link.get()->get_data(6)->data);

    m_link.get()->del_reciprocal(8);
    GTEST_ASSERT_EQ(1,m_link.get()->get_data(0)->data);
}

