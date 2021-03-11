//
// Created by jaime on 2021/3/6.
//

#ifndef TREE_BTREE_H
#define TREE_BTREE_H

#include <memory>
#include <iostream>
#include <map>

using namespace std;

template <typename T>
struct BNode {
    BNode<T>* left;
    BNode<T>* right;
    T data;
};

template <typename T>
class Btree {
public:
    Btree() {

    }

    ~Btree() {

    }

public:
    BNode<T>* find(T data) {
        auto p = this->m_root;
        while (p != nullptr) {
            if (p->data < data) {
                p = p->right;
            } else if (p->data > data) {
                p = p->left;
            } else {
                return p;
            }
        }
        return nullptr;
    }
    void insert(T data) {
        auto node = this->createNode(data);
        if (this->m_root == nullptr) {
            this->m_root = node;
            return;
        }
        auto p = this->m_root;
        while (p != nullptr) {
            if (p->data < data) {
                if (p->right == nullptr) {
                   p->right = node;
                    return;
                }
                p = p->right;
            } else {
                if (p->left == nullptr) {
                    p->left = node;
                    return;
                }
                p = p->left;
            }
        }
    }
    void del(T data) {
        auto p = this->m_root;
        auto prev = p;
        while (p != nullptr) {
            prev = p;
            if (p->data > data) {
                p = p->left;
            } else if(p->data < data) {
                p = p->right;
            } else {
                break;
            }
        }
        if (p == nullptr) {
            cout<<"not found"<<endl;
            return;
        }
        if ((p->left != nullptr) && (p->right != nullptr)) {
            auto rptr = p->right;
            auto rp_parent = rptr;
            while (rptr != nullptr) {
                rp_parent = rptr;
                if (rptr->left != nullptr) {
                    rptr = rptr->left;
                }
                break;
            }
            p->data = rptr->data;
            rp_parent->left = nullptr;
            delete rptr;
            rptr = nullptr;
            return;
        }
        BNode<T>* node = nullptr;
        if (p->left != nullptr) {
            node = p->left;
        } else if(p->right != nullptr) {
            node = p->right;
        } else {
            node = nullptr;
        }
        if (prev == nullptr) {
            return;
        } else if(prev->left == p) {
            prev->left = node;
        } else if (prev->right == p){
            prev->right = node;
        } else {
            delete this->m_root;
            this->m_root = nullptr;
        }
    }

private:
    BNode<T>* createNode(T data) {
        auto node = new BNode<T>();
        node->left = nullptr;
        node->right = nullptr;
        node->data = data;
        return node;
    }

    BNode<T>* m_root = nullptr;
};



#endif //TREE_BTREE_H
