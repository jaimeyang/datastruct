//
// Created by TestAdmin on 2020/10/13.
//

#ifndef CONSISTENTHASH_CONSISTENTHASH_H
#define CONSISTENTHASH_CONSISTENTHASH_H

#include <memory>
#include <vector>
#include <map>
using namespace std;
//一致性HASH算法实现
const int MAX_VIRTUAL_NODE = 64;
class ConsistentHash {
public:
    ConsistentHash(){

    }
    ~ConsistentHash(){
        remove_all_server();
    }
    void add_server(const char* server);
    void rem_server(const char* server);
    const char* get_server(const char* key);
    void remove_aerver(const char* server);
private:
    void has_all_server();
    void remove_all_server();
    void ketama_md5_digest( char* inString, unsigned char md5pword[16]);
    unsigned int ketama_hashi( char* inString );
private:
   map<unsigned int,const char*> m_servers;
};


#endif //CONSISTENTHASH_CONSISTENTHASH_H
