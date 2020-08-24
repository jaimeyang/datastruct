#include <gtest/gtest.h>
#include "../../CircleLInk.h"
#include <memory>

using namespace std;

class TestCircle : public ::testing::Test{
public:
    TestCircle(){

    }
    ~TestCircle(){

    }

    void SetUp(){
        m_link = make_unique<CircleLink<int>>();
    }

    void TearDown(){

    }

    unique_ptr<CircleLink<int>> m_link;
};


TEST_F(TestCircle,test_insert){
    GTEST_ASSERT_EQ(m_link.get()->insert(10,0),0);
    int d0 = m_link.get()->get_data(0)->data;
    GTEST_ASSERT_EQ(10,d0);

    int d1 = m_link.get()->get_data(2)->data;
    GTEST_ASSERT_EQ(10,d1);

    GTEST_ASSERT_EQ(m_link.get()->insert(22,1),0);
    int d2 = m_link.get()->get_data(3)->data;
    GTEST_ASSERT_EQ(22,d2);

    int d3 = m_link.get()->get_data(4)->data;
    GTEST_ASSERT_EQ(10,d1);
}

TEST_F(TestCircle,test_del){
    for (int i = 0; i < 10; ++i) {
        m_link.get()->insert(i,i);
    };

    m_link.get()->del(20);
    GTEST_ASSERT_EQ(m_link.get()->get_data(0)->data,1);

    m_link.get()->del(20);
    GTEST_ASSERT_EQ(m_link.get()->get_data(2)->data,4);

    m_link.get()->del(20);
    GTEST_ASSERT_EQ(m_link.get()->get_data(4)->data,7);

    for (int j = 0; j < 7; ++j) {
        m_link.get()->del(0);
    }
    GTEST_ASSERT_EQ(m_link.get()->del(0),-1);
}