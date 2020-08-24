//
// Created by jaime on 2020/8/24.
//


#include <gtest/gtest.h>
#include <memory>
#include "../../LruCache.h"

using namespace std;

const int MAX_SIZE = 5;

class TestLruCache : public ::testing::Test{
public:
    TestLruCache(){

    }
    ~TestLruCache(){

    }

    void SetUp(){
        m_lru = make_unique<LruCache>(MAX_SIZE);
    }

    void TearDown(){

    }

    unique_ptr<LruCache> m_lru;
};

TEST_F(TestLruCache,test_put_in_lru){
    m_lru.get()->put_in_cache(1);
    ASSERT_EQ(1,m_lru.get()->get_in_cache(0));

    m_lru.get()->put_in_cache(3);
    ASSERT_EQ(3,m_lru.get()->get_in_cache(0));

    m_lru.get()->put_in_cache(4);
    ASSERT_EQ(4,m_lru.get()->get_in_cache(0));

    m_lru.get()->put_in_cache(1);
    ASSERT_EQ(1,m_lru.get()->get_in_cache(0));

    m_lru.get()->put_in_cache(11);
    ASSERT_EQ(11,m_lru.get()->get_in_cache(0));

    m_lru.get()->put_in_cache(12);
    ASSERT_EQ(12,m_lru.get()->get_in_cache(0));

    m_lru.get()->put_in_cache(13);
    ASSERT_EQ(13,m_lru.get()->get_in_cache(0));

    m_lru.get()->put_in_cache(12);
    ASSERT_EQ(12,m_lru.get()->get_in_cache(0));
}