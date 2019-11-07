//
// Created by waether on 20/10/19.
//

#ifndef    NET_HPP_
# define  NET_HPP_

#include "NetException.hpp"

#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string>

class Net
{
private:
    int					_sock;
    struct sockaddr_in	serv_addr;

public:
	Net(const char *addr, uint16_t port);

    ~Net();

    bool Connect();

    bool SendMsg(const std::string & message);

    std::string ReceiveMsg();

};

#endif		//NET_HPP_
