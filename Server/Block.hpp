#ifndef BLOCK_H
#define BLOCK_H

#include <cstdint> 
#include <iostream>
#include <sstream>

using namespace std;

class Block {
    public:
        string prevHash;
        Block(uint32_t indexIn, const string &dataIn);
        string getHash();
        void mineBlock(uint32_t difficulty);
        string getData() const;

    private:
        uint32_t _index;
        int64_t _nonce;
        string _data;
        string _hash;
        time_t _time;

        string _calculateHash() const;
};

#endif