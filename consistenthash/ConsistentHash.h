//
// Created by TestAdmin on 2020/10/13.
//

#ifndef CONSISTENTHASH_CONSISTENTHASH_H
#define CONSISTENTHASH_CONSISTENTHASH_H

#include <memory>
#include <vector>
using namespace std;
//一致性HASH算法实现

typedef struct ServerHash {
    const char* server;
    int hash;
}ServerHash;

class ConsistentHash {
public:
    ConsistentHash();
    ~ConsistentHash(){
        remove_all_server();
    }
    void add_server(const char* server);
    const char* get_server(const char* key);
    void remove_aerver(const char* server);
private:
    void has_all_server();
    void remove_all_server();
private:
   vector<ServerHash*> m_servers;
};


#endif //CONSISTENTHASH_CONSISTENTHASH_H
