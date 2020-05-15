#ifndef BLOCK_H
#define BLOCK_H

#include <cstdint> 
#include <iostream>
#include <sstream>
#include <algorithm>
#include <bits/stdc++.h> 

using namespace std;

class Block {
    public:
        string prevHash;
        Block();
        string getHash();
        string getData();
        void clear();
        void mineBlock();
        int transactions();
        void addData(string data);

    private:
        uint32_t _index;
        int64_t _nonce;
        string _data;
        string _hash;
        time_t _time;

        string _calculateHash() const;
};

#endif