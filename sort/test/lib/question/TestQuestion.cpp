//
// Created by TestAdmin on 2020/9/15.
//

#include <gtest/gtest.h>
#include <memory>
#include "../../../Question.h"

using namespace std;

class TestQuestion : public testing::Test{
public:
    void SetUp(){
        m_sort = std::make_unique<Question>();
    }

    void TearDown(){

    }

protected:
    unique_ptr<Question> m_sort;
};

TEST_F(TestQuestion,test_question){
    auto a1 = std::make_shared<int>(6);
    for (int i = 0; i < 6; ++i) {
        a1.get()[i] = i;
    }
    auto r1 = m_sort.get()->k_max_select(a1,6,1);
    GTEST_ASSERT_EQ(5,r1);

    auto a4 = std::make_shared<int>(11);
    int b1[] = {1,23,12,6,44,100,12,66,12,55,2};
    for (int i = 0; i < 11; i++){
        a4.get()[i] = b1[i];
    }
    auto r2 = m_sort.get()->k_max_select(a4,11,1);
    GTEST_ASSERT_EQ(100,r2);
//
    auto a2 = std::make_shared<int>(7);
    auto j = 20;
    for (int i = 0; i < 7; ++i) {
        a2.get()[i] = j - i;
    }
    auto r3 = m_sort.get()->k_max_select(a2,7,1);
    GTEST_ASSERT_EQ(20,r3);

}