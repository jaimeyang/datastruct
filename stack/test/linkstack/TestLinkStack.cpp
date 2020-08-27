//
// Created by jaime on 2020/8/27.
//

//
// Created by jaime on 2020/8/26.
//

#include "gtest/gtest.h"
#include "../../LinkStack.h"
#include <memory>


using namespace std;

class TestLinkStack : public testing::Test{
public:
    void SetUp(){
        m_stack = make_unique<LinkStack<int>>(10);
    }

    void TearDown(){

    }

public:
    unique_ptr<LinkStack<int>> m_stack;
};

TEST_F(TestLinkStack,test_operate){
    GTEST_ASSERT_EQ(m_stack.get()->pop(),-1);
    m_stack.get()->push(10);
    GTEST_ASSERT_EQ(m_stack.get()->top()->data,10);
    m_stack.get()->pop();
    GTEST_ASSERT_EQ(m_stack.get()->top(), nullptr);

    for (int i = 0; i < 10; ++i) {
        m_stack.get()->push(i);
    }
    GTEST_ASSERT_EQ(m_stack.get()->top()->data,9);
    GTEST_ASSERT_EQ(m_stack.get()->push(1),-1);
    m_stack.get()->pop();
    m_stack.get()->push(11);
    GTEST_ASSERT_EQ(m_stack.get()->top()->data,11);

    for (int i = 0; i < 10; ++i) {
        m_stack.get()->pop();
    }
    GTEST_ASSERT_EQ(m_stack.get()->top(), nullptr);
    GTEST_ASSERT_EQ(m_stack.get()->pop(),-1);
}