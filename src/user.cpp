#include "user.hpp"

int main() {
    User user;

    string data;
    user.connectToNetwork();
    cin >> data;
    while (data.compare("end") != 0) 
    {
        user.sendData(data);
        cin >> data;
    }
    return 0;
}

User::User()
{
    _userId = 1;
}

bool User::connectToNetwork()
{
    return _talker.openSock();
}

BlockChain User::getLedger()
{
    return _ledger;
}

bool User::sendData(string data)
{
    _talker.sendData(data);
}


