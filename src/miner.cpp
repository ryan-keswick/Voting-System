#include "BlockChain.hpp"
#include <iostream>
#include <fstream>

int main() {
    BlockChain chain = BlockChain();

    cout << "Mining block 1..." << endl;
    chain.addBlock(Block(1, "Block 1 Data"));

    cout << "Mining block 2..." << endl;
    chain.addBlock(Block(2, "Block 2 Data"));
 
    cout << "Mining block 3..." << endl;
    chain.addBlock(Block(3, "Block 3 Data"));

    ofstream debugFile;
    debugFile.open("debugChain.txt");
    for (Block block : chain.getChain()) {
        debugFile << "PrevHash " << block.prevHash << endl;
        debugFile << "Data: " << block.getData() << endl;
        debugFile << "CurrHash " << block.getHash() << endl;
        debugFile << endl;
    }
    debugFile.close();
    return 0;
}