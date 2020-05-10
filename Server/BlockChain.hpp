#ifndef BLOCKCHAIN_H
#define BLOCKCHAIN_H

#include <cstdint>
#include <vector>
#include "Block.hpp"

using namespace std;

class BlockChain {
    public:
        BlockChain();
        void addBlock(Block newBlock);
        vector<Block> getChain();

    private:
        uint32_t _difficulty;
        vector<Block> _chain;
        Block _getLastBlock() const;
};

#endif