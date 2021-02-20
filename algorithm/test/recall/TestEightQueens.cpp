//
// Created by jaime on 2021/2/18.
//

#ifndef ALGORITHM_TESTEIGHTQUEENS_CPP
#define ALGORITHM_TESTEIGHTQUEENS_CPP

#include "gtest/gtest.h"
#include <iostream>
#include "EightQueens.h"
#include <memory>

using namespace std;

class TestEightQueens : public ::testing::Test {
public:
    TestEightQueens() {

    }

    ~TestEightQueens() {

    }

    void SetUp() {
        m_eight = std::make_unique<EightQueens>();
    }


    void TestBody() {

    }

    void TearDown() {

    }

public:
    unique_ptr<EightQueens> m_eight;
};
//TEST_F的test_name要以test开头
TEST_F(TestEightQueens,test_eight_queens) {
    m_eight->recall_eight(0);
    auto result = m_eight->getResult();
    for (auto item : result) {
        for (int row = 0; row < 8; ++row) {
            for (int column = 0; column < 8; ++column) {
                if ( item.at(row) == column){
                    cout<<"Q";
                }else{
                    cout<<"*";
                }
            }
            cout<<"\n";
        }
        cout<<"------------------"<<endl;
    }
}

#endif //ALGORITHM_TESTEIGHTQUEENS_CPP
