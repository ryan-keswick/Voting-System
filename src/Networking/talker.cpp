#include "talker.hpp"

Talker::Talker() 
{
	// Default hostName
	_hostName = "localhost";

	memset(&_hints, 0, sizeof _hints);
	_hints.ai_family = AF_UNSPEC;
	_hints.ai_socktype = SOCK_DGRAM;

	if ((_rv = getaddrinfo(_hostName.c_str(), 
							SERVERPORT, 
							&_hints, 
							&_servinfo)) != 0) 
    {
		fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(_rv));
	}
}

bool Talker::openSock()
{
	// loop through all the results and make a socket
	for(_p = _servinfo; _p != NULL; _p = _p->ai_next) {
		if ((_sockfd = socket(_p->ai_family, _p->ai_socktype,
				_p->ai_protocol)) == -1) {
			perror("talker: socket");
			continue;
		}
		break;
	}

	if (_p == NULL) 
	{
		fprintf(stderr, "talker: failed to create socket\n");
		return false;
	}
	return true;
}

int Talker::sendData(string message)
{
	int numbytes = 0;
	if ((numbytes = sendto(_sockfd, message.c_str(), message.length(), 0,
			_p->ai_addr, _p->ai_addrlen)) == -1) {
		perror("talker: sendto");
		return -1;
	}
	return numbytes;
}

bool Talker::closeSock()
{
	freeaddrinfo(_servinfo);
	close(_sockfd);
	return true;
}