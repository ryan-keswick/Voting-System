#include "BlockChain.hpp"

int main() {
    BlockChain chain = BlockChain();

    cout << "Mining block 1..." << endl;
    chain.addBlock(Block(1, "Block 1 Data"));

    cout << "Mining block 2..." << endl;
    chain.addBlock(Block(2, "Block 2 Data"));
 
    cout << "Mining block 3..." << endl;
    chain.addBlock(Block(3, "Block 3 Data"));
    
    return 0;
}