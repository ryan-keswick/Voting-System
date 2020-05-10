#include "Block.hpp"
#include "sha256/sha256.h"

/**
 * @brief The constructor when a new block is created 
 * 
 * @param indexIn 
 * @param dataIn    The data to be put in the new block 
 */
Block::Block(uint32_t indexIn, const string &dataIn) {
    _nonce = -1;
    _time = time(nullptr);
}

/**
 * @brief Returns the blocks hash
 * 
 * @return string The hash of the block
 */
string Block::getHash() {
    return _hash;
}

/**
 * @brief A function that is used to mine a block
 * 
 * First the a diffuculty modifer is used to make the hash easier to crack
 * This is mostly used for testing, a difficulty of 2 means that only 2 
 * characters in the hash are needed to be cracked.
 * 
 * Then the do while loop tries to crack hash by brute force
 * 
 * @param difficulty 
 */
void Block::mineBlock(uint32_t difficulty) {
    char strDiff[difficulty + 1];
    for (uint32_t i = 0; i < difficulty; ++i) {
        strDiff[i] = '0';
    }
    strDiff[difficulty] = '\0';

    string str(strDiff);

    do {
        _nonce++;
        _hash = _calculateHash();
    } while (_hash.substr(0, difficulty) != str);

    cout << "Block mined: " << _hash << endl;
}

/**
 * @brief Makes an unique hash given a unique input
 * 
 * @return string Returns the hash
 */
inline string Block::_calculateHash() const {
    stringstream ss;
    ss << _index << _time << _data << _nonce << prevHash;
    return sha256(ss.str());
}