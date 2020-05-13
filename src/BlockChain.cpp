#include "BlockChain.hpp"

/**
 * @brief Construct a new Block Chain:: Block Chain object
 *  The higher the difficulty number it is the longer it takes to mine 
 */
BlockChain::BlockChain() {
    _chain.emplace_back(Block(0, "Genesis Block"));
    _difficulty = 4;
}

/**
 * @brief Adds a new block to the blockchain
 * @param newBlock The new block to be added
 */
void BlockChain::addBlock(Block newBlock) {
    newBlock.prevHash = _getLastBlock().getHash();
    newBlock.mineBlock(_difficulty);
    _chain.push_back(newBlock);
}

Block BlockChain::_getLastBlock() const {
    return _chain.back();
}

vector<Block> BlockChain::getChain() {
    return _chain;
}