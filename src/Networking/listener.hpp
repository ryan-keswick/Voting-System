#ifndef LISTENER_H 
#define LISTENER_H

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

#define MYPORT "4950"	// the port users will be connecting to
#define MAXBUFLEN 100

using namespace std;

class Listener {
    public:
        Listener();
        string getData();

    private:
        void *get_in_addr(struct sockaddr *sa);
        int _sockfd;
        struct addrinfo _hints, *_servinfo, *_p;
        socklen_t _addr_len;
        struct sockaddr_storage _their_addr;
        int _rv;
        string _hostName;
        void closeSock();
        bool openSock();
};

#endif