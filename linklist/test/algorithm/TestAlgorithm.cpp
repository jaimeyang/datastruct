//
// Created by jaime on 2020/8/18.
//

#include <gtest/gtest.h>
#include <memory>
#include "../../Algorithm.h"

using namespace std;

class TestAlgorithm : public ::testing::Test{
public:
    TestAlgorithm(){

    }
    ~TestAlgorithm(){

    }

    void SetUp(){
        m_algorithm = make_unique<Algorithm>();
    }

    void TearDown(){

    }

    auto create_list(const char* data){
        auto link = make_unique<SingleLink<char>>();
        auto len = strlen(data);
        char* p = const_cast<char *>(data);
        for (int i = 0; i < len; ++i) {
            link.get()->push_back(*p);
            p++;
        }
        return std::move(link);
    }

    auto crate_shareptr_list(const char* data){
        auto link = make_shared<SingleLink<char>>();
        auto len = strlen(data);
        char* p = const_cast<char *>(data);
        for (int i = 0; i < len; ++i) {
            link.get()->push_back(*p);
            p++;
        }
        return link;
    }

    auto create_circle_list(const char* data,int index1,int index2){
        auto link = make_shared<SingleLink<char>>();
        auto len = strlen(data);
        char* p = const_cast<char *>(data);
        for (int i = 0; i < len; ++i) {
            link.get()->push_back(*p);
            p++;
        }
        auto node = link.get()->get_data(index1);
        auto node1 = link.get()->get_data(index2);
        node->next = node1;
        return link;
    }

    unique_ptr<Algorithm> m_algorithm;
};

TEST_F(TestAlgorithm,test_palindrome){
    auto link = create_list("level");
    GTEST_ASSERT_EQ(m_algorithm.get()->is_palindrome(std::move(link)), true);

    auto link1 = create_list("level1");
    GTEST_ASSERT_EQ(m_algorithm.get()->is_palindrome(std::move(link1)), false);

    auto link2 = create_list("noon");
    GTEST_ASSERT_EQ(m_algorithm.get()->is_palindrome(std::move(link2)), true);

    auto link3 = create_list("");
    GTEST_ASSERT_EQ(m_algorithm.get()->is_palindrome(std::move(link3)), true);

    auto link4 = create_list("race a car");
    GTEST_ASSERT_EQ(m_algorithm.get()->is_palindrome(std::move(link4)), false);

    auto link5 = create_list("level a level");
    GTEST_ASSERT_EQ(m_algorithm.get()->is_palindrome(std::move(link5)), true);
}

TEST_F(TestAlgorithm,test_reverse){
    auto link = crate_shareptr_list("wokaotest");
    m_algorithm.get()->reverse(link);
    char* test_data = "tsetoakow";
    for (int i = 0; i < link.get()->size(); ++i) {
        GTEST_ASSERT_EQ(*test_data,link.get()->get_data(i)->data);
        test_data++;
    }
}

TEST_F(TestAlgorithm,test_is_circle){
    auto link = crate_shareptr_list("sssdsfasdf");
    GTEST_ASSERT_EQ(false,m_algorithm.get()->isCircle(link));

    auto link1 = create_circle_list("1234dfasd56",3,1);
    GTEST_ASSERT_EQ(true,m_algorithm.get()->isCircle(link1));

    auto link2 = create_circle_list("1234dfasd56",4,0);
    GTEST_ASSERT_EQ(true,m_algorithm.get()->isCircle(link1));
}
