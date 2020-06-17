#include "user.hpp"

int main() {
    User user;

    string data;
    user.connectToNetwork();
    cin >> data;
    user.sendData(data);
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

void User::sendData(string data)
{
    _talker.sendData(data);
}


