#ifndef USER_H
#define USER_H
#include "Networking/listener.hpp"
#include "Networking/talker.hpp"
#include <iostream>
#include <fstream>
#include "BlockChain.hpp"
#include "Block.hpp"

class User {
    public:
        User();
        int getUserId();
        BlockChain getLedger();
        bool connectToNetwork();
        bool sendData(string data);

    private:
        int _userId;
        void sendTransaction();
        BlockChain _ledger;
        Talker _talker;
        Listener _listener;
};

#endif