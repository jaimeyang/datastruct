//
// Created by jaime on 2020/9/7.
//
#include "gtest/gtest.h"
#include "../../../Sort.h"
#include <memory>

using namespace std;

class TestSort : public testing::Test{
public:
    void SetUp(){
        m_sort = std::make_unique<Sort>();
    }

    void TearDown(){

    }

protected:
    unique_ptr<Sort> m_sort;
};

TEST_F(TestSort,test_direct){
    auto a1 = std::make_unique<int>(6);
    for (int i = 0; i < 6; ++i) {
        a1.get()[i] = i;
    }
    auto r1 = m_sort.get()->sort_direct(std::move(a1),6);
    for (int i = 0; i < 6; ++i) {
        GTEST_ASSERT_EQ(i,r1.get()[i]);
    }
//
    auto a4 = std::make_unique<int>(10);
    int b1[] = {1,23,12,6,44,12,66,12,55,2};
    for (int i = 0; i < 10; i++){
        a4.get()[i] = b1[i];
    }
    auto r3 = m_sort.get()->sort_direct(std::move(a4),10);
    int b2[] = {1,2,6,12,12,12,23,44,55,66};
    for (int i = 0; i < 10; ++i) {
        GTEST_ASSERT_EQ(b2[i],r3.get()[i]);
    }

    auto a2 = std::make_unique<int>(7);
    auto j = 20;
    for (int i = 0; i < 7; ++i) {
        a2.get()[i] = j - i;
    }
    auto r2 = m_sort.get()->sort_direct(std::move(a2),7);
    for (int i = 0; i < 7; ++i) {
        GTEST_ASSERT_EQ(14 + i,r2.get()[i]);
    }
}

TEST_F(TestSort,test_bable){
    auto a1 = std::make_unique<int>(6);
    for (int i = 0; i < 6; ++i) {
        a1.get()[i] = i;
    }
    auto r1 = m_sort.get()->sort_bable(std::move(a1),6);
    for (int i = 0; i < 6; ++i) {
        GTEST_ASSERT_EQ(i,r1.get()[i]);
    }
//
    auto a4 = std::make_unique<int>(11);
    int b1[] = {1,23,12,6,44,100,12,66,12,55,2};
    for (int i = 0; i < 11; i++){
        a4.get()[i] = b1[i];
    }
    auto r3 = m_sort.get()->sort_bable(std::move(a4),11);
    int b2[] = {1,2,6,12,12,12,23,44,55,66,100};
    for (int i = 0; i < 11; ++i) {
        GTEST_ASSERT_EQ(b2[i],r3.get()[i]);
    }
//
    auto a2 = std::make_unique<int>(7);
    auto j = 20;
    for (int i = 0; i < 7; ++i) {
        a2.get()[i] = j - i;
    }
    auto r2 = m_sort.get()->sort_bable(std::move(a2),7);
    for (int i = 0; i < 7; ++i) {
        GTEST_ASSERT_EQ(14 + i,r2.get()[i]);
    }
}

TEST_F(TestSort,test_select){
    auto a1 = std::make_unique<int>(6);
    for (int i = 0; i < 6; ++i) {
        a1.get()[i] = i;
    }
    auto r1 = m_sort.get()->sort_select(std::move(a1),6);
    for (int i = 0; i < 6; ++i) {
        GTEST_ASSERT_EQ(i,r1.get()[i]);
    }
//
    auto a4 = std::make_unique<int>(11);
    int b1[] = {1,23,12,6,44,100,12,66,12,55,2};
    for (int i = 0; i < 11; i++){
        a4.get()[i] = b1[i];
    }
    auto r3 = m_sort.get()->sort_select(std::move(a4),11);
    int b2[] = {1,2,6,12,12,12,23,44,55,66,100};
    for (int i = 0; i < 11; ++i) {
        GTEST_ASSERT_EQ(b2[i],r3.get()[i]);
    }
//
    auto a2 = std::make_unique<int>(7);
    auto j = 20;
    for (int i = 0; i < 7; ++i) {
        a2.get()[i] = j - i;
    }
    auto r2 = m_sort.get()->sort_select(std::move(a2),7);
    for (int i = 0; i < 7; ++i) {
        GTEST_ASSERT_EQ(14 + i,r2.get()[i]);
    }
}

TEST_F(TestSort,test_bable_2){
    auto a1 = std::make_unique<int>(6);
    for (int i = 0; i < 6; ++i) {
        a1.get()[i] = i;
    }
    auto r1 = m_sort.get()->sort_bable_2(std::move(a1),6);
    for (int i = 0; i < 6; ++i) {
        GTEST_ASSERT_EQ(i,r1.get()[i]);
    }
//
    auto a4 = std::make_unique<int>(11);
    int b1[] = {1,23,12,6,44,100,12,66,12,55,2};
    for (int i = 0; i < 11; i++){
        a4.get()[i] = b1[i];
    }
    auto r3 = m_sort.get()->sort_bable_2(std::move(a4),11);
    int b2[] = {1,2,6,12,12,12,23,44,55,66,100};
    for (int i = 0; i < 11; ++i) {
        GTEST_ASSERT_EQ(b2[i],r3.get()[i]);
    }
//
    auto a2 = std::make_unique<int>(7);
    auto j = 20;
    for (int i = 0; i < 7; ++i) {
        a2.get()[i] = j - i;
    }
    auto r2 = m_sort.get()->sort_bable_2(std::move(a2),7);
    for (int i = 0; i < 7; ++i) {
        GTEST_ASSERT_EQ(14 + i,r2.get()[i]);
    }
}

TEST_F(TestSort,test_merge){
    auto a1 = std::make_shared<int>(6);
    for (int i = 0; i < 6; ++i) {
        a1.get()[i] = i;
    }
    m_sort.get()->sort_merge(a1,6);
    for (int i = 0; i < 6; ++i) {
        GTEST_ASSERT_EQ(i,a1.get()[i]);
    }
////
//    auto a4 = std::make_unique<int>(11);
//    int b1[] = {1,23,12,6,44,100,12,66,12,55,2};
//    for (int i = 0; i < 11; i++){
//        a4.get()[i] = b1[i];
//    }
//    auto r3 = m_sort.get()->sort_bable_2(std::move(a4),11);
//    int b2[] = {1,2,6,12,12,12,23,44,55,66,100};
//    for (int i = 0; i < 11; ++i) {
//        GTEST_ASSERT_EQ(b2[i],r3.get()[i]);
//    }
////
//    auto a2 = std::make_unique<int>(7);
//    auto j = 20;
//    for (int i = 0; i < 7; ++i) {
//        a2.get()[i] = j - i;
//    }
//    auto r2 = m_sort.get()->sort_bable_2(std::move(a2),7);
//    for (int i = 0; i < 7; ++i) {
//        GTEST_ASSERT_EQ(14 + i,r2.get()[i]);
//    }
}
