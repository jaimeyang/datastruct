//
// Created by TestAdmin on 2020/10/13.
//

#include "ConsistentHash.h"

void ConsistentHash::add_server(const char *server) {
    auto item = new ServerHash();
    item->server = server;

    m_servers.push_back(item);
}
