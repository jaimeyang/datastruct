//
// Created by TestAdmin on 2020/9/24.
//
#include <gtest/gtest.h>
#include <memory>
#include "../SkipList.h"

using namespace std;

class TestSkipList : public testing::Test{
public:
    // Sets up the test fixture.
    virtual void SetUp(){
        m_search = make_unique<SkipList>();
    }

    // Tears down the test fixture.
    virtual void TearDown(){

    }
    std::unique_ptr<SkipList> m_search;
};


TEST_F(TestSkipList,test_skiplist){
    auto node = m_search.get()->find(1);
    GTEST_ASSERT_EQ(node, nullptr);

    m_search.get()->insert(10);
    auto node1 = m_search.get()->find(10);
    GTEST_ASSERT_EQ(node1->data,10);

    m_search.get()->remove(10);
    auto node2 = m_search.get()->find(10);
    GTEST_ASSERT_EQ(node2, nullptr);
}
