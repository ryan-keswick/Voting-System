#ifndef MINER_H 
#define MINER_H
#include "Networking/listener.hpp"
#include "Networking/talker.hpp"
#include <iostream>
#include <fstream>
#include "BlockChain.hpp"
#include "Block.hpp"

class Miner {
    public:
        Miner();
        int getMinerId();
        BlockChain getLedger();

    private:
        bool connectToNetwork();
        void startMining();
        bool addDataToBlock(string data, Block block);
        int _minerId;
        BlockChain _ledger;
        Block _blockToAdd;
        Talker _talker;
        void sendBlock();
        Listener _listener;
};

#endif