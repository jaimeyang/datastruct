//
// Created by jaime on 2021/2/18.
//

#ifndef ALGORITHM_TESTEIGHTQUEENS_CPP
#define ALGORITHM_TESTEIGHTQUEENS_CPP

#include "gtest/gtest.h"
#include <iostream>
#include "Bag.h"
#include <memory>

using namespace std;

class TestBag : public ::testing::Test {
public:
    TestBag() {

    }

    ~TestBag() {

    }

    void SetUp() {
        m_bag = std::make_unique<Bag>();
    }



    void TestBody() {

    }

    void TearDown() {

    }

public:
    unique_ptr<Bag> m_bag;
};
//TEST_F的test_name要以test开头
TEST_F(TestBag,test_bag) {
    int max_w = 100;
    vector<int> data = {1,2,3,4,5,6,7,8,9,10};
    auto max_ew = m_bag->recall(0,data,0,100);
    ASSERT_EQ(max_ew,55);
}

TEST_F(TestBag,test_bag_1) {
    int max_w = 100;
    vector<int> data = {1,12,3,4,5,6,7,9,88,110};
    auto max_ew = m_bag->recall(0,data,0,100);
    ASSERT_EQ(max_ew,47);
}

#endif //ALGORITHM_TESTEIGHTQUEENS_CPP
