//
// Created by TestAdmin on 2020/9/15.
//
#include <gtest/gtest.h>
#include "../Search.h"

class TestSearch : public testing::Test{
public:
    // Sets up the test fixture.
    virtual void SetUp(){
        m_search = make_unique<Search>();
    }

    // Tears down the test fixture.
    virtual void TearDown(){

    }
    std::unique_ptr<Search> m_search;
};

TEST_F(TestSearch,test_binary){
    auto a1 = std::make_shared<int>(11);
    int b1[] = {1,3,45,67,878,1000,10002,10003,10004,10005,10006};
    for (int i = 0; i < 11; i++){
        a1.get()[i] = b1[i];
    }
    auto index = m_search.get()->serach_binary(a1,11,878);
    GTEST_ASSERT_EQ(index,4);

}

TEST_F(TestSearch,test_sqare){
    auto a1 = m_search.get()->square(100);
    GTEST_ASSERT_EQ(10,a1);
}