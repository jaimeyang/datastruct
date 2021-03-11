//
// Created by jaime on 2021/3/7.
//

#include "TestBtree.h"
#include <iostream>
#include <memory>
#include <random>

using namespace std;

weak_ptr<int> testMoveSptr(shared_ptr<int> data) {
    cout<<"p1 move "<<data.use_count()<<endl;
    cout<<"data is "<<data.get()[0]<<endl;
    return data;
}

TEST_F(TestBtree,test_shareptrMove) {
    auto p1 = make_shared<int>(2);
    p1.get()[0] = 10;
    auto p2 = testMoveSptr(p1);
}

TEST_F(TestBtree,test_treeInsert) {
    unique_ptr<Btree<int>> b = make_unique<Btree<int>>();
    auto r1 = b->find(10);
    ASSERT_EQ(r1, nullptr);

    b->insert(2000);
    auto r2 = b->find(2000);
    ASSERT_EQ(r2->data,2000);

    vector<int> vec;
    std::random_device dev;
    const auto seed = dev.entropy() ? dev() : time(nullptr);
    mt19937 eng(static_cast<mt19937::result_type>(seed));
    for (int i = 0; i < 100; ++i) {
        uniform_int_distribution<int> dist(1,1000);
        auto data = dist(eng);
        vec.push_back(data);
        b->insert(data);
    }

    for (int i = 0; i < vec.size(); ++i) {
        auto data = vec.at(i);
        auto node = b->find(data);
        ASSERT_NE(node, nullptr);
    }


}

TEST_F(TestBtree,test_treedel) {
    unique_ptr<Btree<int>> b = make_unique<Btree<int>>();
    b->insert(2000);

    b->del(2000);
    auto d1 = b->find(2000);
    ASSERT_EQ(d1, nullptr);

    
}