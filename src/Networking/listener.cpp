#include "listener.hpp"

Listener::Listener() 
{
    memset(&_hints, 0, sizeof _hints);
    _hints.ai_family = AF_UNSPEC;        // Set to AF_INET to force IPv4
    _hints.ai_socktype = SOCK_DGRAM;
    _hints.ai_flags = AI_PASSIVE;        // Use my IP

    if ((_rv = getaddrinfo(NULL, MYPORT, &_hints, &_servinfo)) != 0) {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(_rv));
        return;
    }

}



bool Listener::openSock()
{
    // Loop through all the results and bind the first we can 
    for (_p = _servinfo; _p != NULL; _p = _p->ai_next) {
        if ((_sockfd = socket(_p->ai_family, 
                             _p->ai_socktype, 
                             _p->ai_protocol)) == -1) {
            perror("listener: socket");
            continue;
        }

        if (bind(_sockfd, _p->ai_addr, _p->ai_addrlen) == -1) {
            close(_sockfd);
            perror("listener: bind");
            continue;
        }

        break;
    }

    if (_p == NULL) {
        fprintf(stderr, "listener: failed to bind socket\n");
        return false;
    }

    freeaddrinfo(_servinfo);
    return true;
}

void Listener::closeSock()
{
    close(_sockfd);
}

// get sockaddr
void *Listener::get_in_addr(struct sockaddr *sa)
{
    switch (sa->sa_family) 
    {
        case AF_INET: 
        {
            sockaddr_in *sin = reinterpret_cast<sockaddr_in*>(sa);
            return &(((struct sockaddr_in*)sa)->sin_addr);;
        }
        case AF_INET6: 
        {
            sockaddr_in6 *sin = reinterpret_cast<sockaddr_in6*>(sa);
            return &(((struct sockaddr_in6*)sa)->sin6_addr);
        }
        default:
            return NULL;
    } 
        
}


string Listener::getData()
{
    printf("\n\n\nlistener: waiting to recvfrom..\n");
    int numbytes;
    char buf[MAXBUFLEN];
    char s[INET6_ADDRSTRLEN];

    _addr_len = sizeof _their_addr;
    if ((numbytes = recvfrom(_sockfd, buf, MAXBUFLEN-1, 0, 
            (struct sockaddr *) &_their_addr, &_addr_len)) == -1) {
        perror("recvfrom");
        exit(1);
    }

    printf("listener: got packet from %s\n", 
            inet_ntop(_their_addr.ss_family, 
                get_in_addr((struct sockaddr *)&_their_addr), 
                s, sizeof s));

    printf("listener: packet is %d bytes long\n", numbytes);
    buf[numbytes] = '\0';
    printf("listener: packet contains \"%s\"\n", buf);
    return buf;
}