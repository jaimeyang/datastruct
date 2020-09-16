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
    double r1 = 10;
    GTEST_ASSERT_EQ(r1,a1);

    auto a2 = m_search.get()->square(200);
    GTEST_ASSERT_EQ(14.142135,a2);
}

TEST_F(TestSearch,test_binary_eq_first){
    auto a1 = std::make_shared<int>(11);
    int b1[] = {1,3,45,999,999,1000,10002,10003,10003,10003,10006};
    for (int i = 0; i < 11; i++){
        a1.get()[i] = b1[i];
    }
    auto index = m_search.get()->search_binary_eq_first(a1,11,999);
    GTEST_ASSERT_EQ(index,3);

    auto index1 = m_search.get()->search_binary_eq_first(a1,11,10003);
    GTEST_ASSERT_EQ(index1,7);
}

TEST_F(TestSearch,test_binary_eq_last){
    auto a1 = std::make_shared<int>(11);
    int b1[] = {1,3,45,999,999,1000,10002,10003,10003,10003,10006};
    for (int i = 0; i < 11; i++){
        a1.get()[i] = b1[i];
    }
    auto index = m_search.get()->search_binary_eq_last(a1,11,999);
    GTEST_ASSERT_EQ(index,4);

    auto index1 = m_search.get()->search_binary_eq_last(a1,11,10003);
    GTEST_ASSERT_EQ(index1,9);
}

TEST_F(TestSearch,test_binary_gt_first){
    auto a1 = std::make_shared<int>(11);
    int b1[] = {1,3,45,999,999,1000,10002,10003,10003,10003,10006};
    for (int i = 0; i < 11; i++){
        a1.get()[i] = b1[i];
    }
    auto index = m_search.get()->search_binary_gt_first(a1,11,999);
    GTEST_ASSERT_EQ(index,3);

    auto index1 = m_search.get()->search_binary_gt_first(a1,11,10003);
    GTEST_ASSERT_EQ(index1,7);

    auto index2 = m_search.get()->search_binary_gt_first(a1,11,46);
    GTEST_ASSERT_EQ(index2,3);

    auto index3 = m_search.get()->search_binary_gt_first(a1,11,10004);
    GTEST_ASSERT_EQ(index3,10);
}

TEST_F(TestSearch,test_binary_lt_last){
    auto a1 = std::make_shared<int>(11);
    int b1[] = {1,3,45,999,999,1000,10002,10003,10003,10003,10006};
    for (int i = 0; i < 11; i++){
        a1.get()[i] = b1[i];
    }
    auto index = m_search.get()->search_binary_lt_last(a1,11,999);
    GTEST_ASSERT_EQ(index,4);

    auto index1 = m_search.get()->search_binary_lt_last(a1,11,10003);
    GTEST_ASSERT_EQ(index1,9);

    auto index2 = m_search.get()->search_binary_lt_last(a1,11,46);
    GTEST_ASSERT_EQ(index2,2);

    auto index3 = m_search.get()->search_binary_lt_last(a1,11,10004);
    GTEST_ASSERT_EQ(index3,9);

    auto index4 = m_search.get()->search_binary_lt_last(a1,11,10009);
    GTEST_ASSERT_EQ(index4,10);
}