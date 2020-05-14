#ifndef TALKER_H 
#define TALKER_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <iostream>

#define SERVERPORT "4950"	// the port users will be connecting to

using namespace std;

class Talker {
    public:
        Talker();
        int sendData(string message);
        bool closeSocket();
        bool openSocket();


    private:
        int _sockfd;
        struct addrinfo _hints, *_servinfo, *_p;
        int _rv;
        string _hostName;

};

#endif