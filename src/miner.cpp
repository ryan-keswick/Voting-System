#include "miner.hpp"

int main() {
    Miner miner;

    ofstream debugFile;
    debugFile.open("debugChain.txt");

    for (Block block : miner.getLedger().getChain()) {
        debugFile << "PrevHash " << block.prevHash << endl;
        debugFile << "Data: " << block.getData() << endl;
        debugFile << "CurrHash " << block.getHash() << endl;
        debugFile << endl;
    }
    debugFile.close();
    return 0;
}

Miner::Miner()
{
    _minerId = 1;
    
    
    startMining();
}

bool Miner::connectToNetwork()
{
    return _listener.openSock();
}

void Miner::startMining()
{
    for (bool i = connectToNetwork(); i != true; i = connectToNetwork())
    {
        cout << "Connecting... " << endl;
    }
    int i = 0;
    while (i != 1)
    {
        string data = _listener.getData();
        if (addDataToBlock(data, _blockToAdd))
        {
            _blockToAdd.mineBlock();
            sendBlock();
        }
    }
}

void Miner::sendBlock()
{
    // TODO send block for others to add to their ledger
}

bool Miner::addDataToBlock(string data, Block block)
{
    block.addData(data);
    if (block.transactions() == 10)
    {
        return true;
    }
    else
    {
        return false;
    }
}

BlockChain Miner::getLedger()
{
    return _ledger;
}