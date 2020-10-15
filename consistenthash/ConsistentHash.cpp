//
// Created by TestAdmin on 2020/10/13.
//

#include "ConsistentHash.h"
#include "md5.h"
#include <cstring>
#include <memory>
#include <iostream>


void ConsistentHash::add_server(const char *server) {
    auto key = ketama_hashi(const_cast<char *>(server));
    m_servers.insert(make_pair(key,server));
    for (int i = 1; i <= MAX_VIRTUAL_NODE; ++i) {
        auto num = 0;
        auto j = i;
        while ( j > 0 ){
            num += 1;
            j = j / 10;
        }
        auto vir_server_len = strlen(server) + 1 + num;
        auto vir_server = new char[vir_server_len];
        memcpy(vir_server,server,vir_server_len);
        auto offset = strlen(server);
        memcpy(vir_server + offset,"&",1);
        offset += 1;
        auto num_str = new char[num];
        sprintf(num_str,"%d",i);
        memcpy(vir_server + offset,num_str,num);
        auto vir_key = ketama_hashi(vir_server);
        free(vir_server);
        m_servers.insert(make_pair(vir_key,server));
    }
}

void ConsistentHash::ketama_md5_digest(char *inString, unsigned char *md5pword) {
    md5_state_t md5state;

    md5_init( &md5state );
    md5_append( &md5state, (unsigned char *)inString, strlen( inString ) );
    md5_finish( &md5state, md5pword );
}

unsigned int ConsistentHash::ketama_hashi(char *inString) {
    unsigned char digest[16];

    ketama_md5_digest( inString, digest );
    return (unsigned int)(( digest[3] << 24 )
                          | ( digest[2] << 16 )
                          | ( digest[1] <<  8 )
                          |   digest[0] );
}

const char *ConsistentHash::get_server(const char *key) {
    auto value = ketama_hashi(const_cast<char *>(key));
    auto it = m_servers.upper_bound(value);
    if (it == m_servers.end()){
        return m_servers.begin()->second;
    }
    return it->second;
}

void ConsistentHash::rem_server(const char *server) {
    auto it = m_servers.begin();
    while ( it != m_servers.end() ){
        if ( strcmp(it->second,server) == 0 ){
            m_servers.erase(it++);
        }else{
            it++;
        }
    }
}
