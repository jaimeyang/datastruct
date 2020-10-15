//
// Created by TestAdmin on 2020/10/14.
//
#include <iostream>
#include "ConsistentHash.h"
#include <cstring>
#include <string>
#include <random>
#include <zconf.h>


void randstr(char *str, const int len)
{
    srand(time(NULL));
    int i;
    for (i = 0; i < len; ++i)
    {
        switch ((rand() % 3))
        {
            case 1:
                str[i] = 'A' + rand() % 26;
                break;
            case 2:
                str[i] = 'a' + rand() % 26;
                break;
            default:
                str[i] = '0' + rand() % 10;
                break;
        }
    }
    str[++i] = '\0';
}

using std::string;
using std::random_device;
using std::default_random_engine;

string strRand(int length) {			// length: 产生字符串的长度
    char tmp;							// tmp: 暂存一个随机数
    string buffer;						// buffer: 保存返回值

    // 下面这两行比较重要:
    random_device rd;					// 产生一个 std::random_device 对象 rd
    default_random_engine random(rd());	// 用 rd 初始化一个随机数发生器 random

    for (int i = 0; i < length; i++) {
        tmp = random() % 36;	// 随机一个小于 36 的整数，0-9、A-Z 共 36 种字符
        if (tmp < 10) {			// 如果随机数小于 10，变换成一个阿拉伯数字的 ASCII
            tmp += '0';
        } else {				// 否则，变换成一个大写字母的 ASCII
            tmp -= 10;
            tmp += 'A';
        }
        buffer += tmp;
    }
    return buffer;
}

auto node1 = 0;
auto node2 = 0;
auto node3 = 0;

void get_server(ConsistentHash* c_hash,const char* key){

    auto server = c_hash->get_server(key);
    if ( strcmp(server,"192.168.1.1:1000") == 0){
        node1 += 1;
    }else if ( strcmp(server,"192.168.1.3:1001") == 0){
        node2 += 1;
    }else if ( strcmp(server,"192.168.1.5:1002") == 0){
        node3 += 1;
    }
}
//结论，一致性HASH算法，虚拟节点数或者节点数越大，分配的更平均，数据迁移的更平和
int main(int argc,char* argv[]){
    auto c_hash = new ConsistentHash();
    c_hash->add_server("192.168.1.1:1000");
    c_hash->add_server("192.168.1.3:1001");
    c_hash->add_server("192.168.1.5:1002");


    string* temp = new string[10000];
    for (int i = 0; i < 10000; ++i) {
        // 下面这两行比较重要:
        random_device rd;
        default_random_engine random(rd());
        int len = random() % 30;
        auto key = strRand(len);
        temp[i] = key;
        get_server(c_hash,key.c_str());
        usleep(1);
    }
    std::cout<<"node1 is "<<node1<<" node2 is "<<node2<<" node3 is "<<node3<<std::endl;
    node1 = node2 = node3 = 0;
    c_hash->add_server("192.168.1.9:1001");
    for (int i = 0; i < 10000; ++i) {
        get_server(c_hash,temp[i].c_str());
    }
    std::cout<<"node1 is "<<node1<<" node2 is "<<node2<<" node3 is "<<node3<<std::endl;

    node1 = node2 = node3 = 0;
    c_hash->rem_server("192.168.1.9:1001");
    for (int i = 0; i < 10000; ++i) {
        get_server(c_hash,temp[i].c_str());
    }
    std::cout<<"node1 is "<<node1<<" node2 is "<<node2<<" node3 is "<<node3<<std::endl;

    return 0;
}

