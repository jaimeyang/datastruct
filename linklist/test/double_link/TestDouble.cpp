//
// Created by jaime on 2020/8/17.
//



#include <gtest/gtest.h>
#include "../../DoubleLink.h"
#include <memory>

using namespace std;

class TestDouble : public ::testing::Test{
public:
    TestDouble(){

    }
    ~TestDouble(){

    }

    void SetUp(){
        m_link = make_unique<DoubleLink<int>>();
    }

    void TearDown(){

    }

    unique_ptr<DoubleLink<int>> m_link;
};

TEST_F(TestDouble,test_insert){
    GTEST_ASSERT_EQ(0,m_link.get()->insert(10,0));
    GTEST_ASSERT_EQ(10,m_link.get()->get_data(0)->data);

    GTEST_ASSERT_EQ(0,m_link.get()->insert(12,0));
    GTEST_ASSERT_EQ(12,m_link.get()->get_data(0)->data);

    GTEST_ASSERT_EQ(0,m_link.get()->insert(23,2));
    GTEST_ASSERT_EQ(23,m_link.get()->get_data(2)->data);

    GTEST_ASSERT_EQ(0,m_link.get()->insert(24,2));
    GTEST_ASSERT_EQ(23,m_link.get()->get_data(3)->data);
}

TEST_F(TestDouble,test_del){
    for (int i = 0; i < 10; ++i) {
        m_link.get()->insert(i,i);
    }

    GTEST_ASSERT_EQ(-1,m_link.get()->del(11));

    GTEST_ASSERT_EQ(0,m_link.get()->del(0));
    GTEST_ASSERT_EQ(1,m_link.get()->get_data(0)->data);
    GTEST_ASSERT_EQ(1,m_link.get()->get_data(1)->prev->data);
    GTEST_ASSERT_EQ(nullptr,m_link.get()->get_data(9));

    GTEST_ASSERT_EQ(0,m_link.get()->del(8));
    GTEST_ASSERT_EQ(nullptr,m_link.get()->get_data(8));
    GTEST_ASSERT_EQ(8,m_link.get()->get_data(7)->data);
}