//
// Created by waether on 20/10/19.
//

#include "Net.hpp"
#include "Logger.hpp"
#include <sstream>

Net::Net(const char *addr, uint16_t port)
{
    Logger::Log() << "Starting Socket Initialization ..." << std::endl;

    if ((_sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        Logger::Error() << "Socket creation error." << std::endl;
        throw NetException::SocketInit();
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(port);

    if(inet_pton(AF_INET, addr, &serv_addr.sin_addr)<=0)
    {
        Logger::Error() << "Invalid address." << std::endl;
        throw NetException::SocketInit();
    }
    Logger::Log() << "Socket Initialized." << std::endl;
}

Net::~Net()
{
    Logger::Log() << "Closing Socket ..." << std::endl;
    close(_sock);
    Logger::Log() << "Socket Closed." << std::endl;
}

bool Net::Connect() {
    Logger::Log() << "Connecting to Server ..." << std::endl;

    if (connect(_sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
    {
        Logger::Error() << "Connection Failed." << std::endl;
        throw NetException::ConFailed();
    }
    Logger::Log() << "Connected to Server." << std::endl;
    return true;
}

bool Net::SendMsg(const std::string & message) {
    Logger::Log() << "Sending Message ..." << std::endl;

    Logger::Debug() << "Msg Content : " << message << std::endl;

    ssize_t result = write(_sock, "\x00\x00\x00\x01", 4); // Temporary Bandage
    result += write(_sock, message.c_str(), message.size());

    if (result < 0) {
        Logger::Error() << "Failed to send Message." << std::endl;
        throw NetException::SendFailed();
    }

    Logger::Log() << "Message Sent." << std::endl;
    return true;
}

std::string Net::ReceiveMsg() {
    Logger::Log() << "Receiving Message ..." << std::endl;

    char buffer[1024] = {0};
    std::string str_result;
    ssize_t read_amount = 1024;

    while (read_amount == 1024) {
        read_amount = read( _sock , buffer, 1024);

        if (read_amount == 0)
        {
            throw NetException::PearDisconnected();
        } else if (read_amount < 0) {
            Logger::Error() << "Socket Broken." << std::endl;
            throw NetException::ConInterrupted();
        }

        buffer[read_amount] = 0;

        ssize_t corrected_read_amount = read_amount;

        if (buffer[0] == 0) //Handling the first 4 bytes of each messages
            for (int f = 0; f < 4; f++) {
                Logger::Error() << "Received 0 as first byte from server." << std::endl;
                for (unsigned int i = 0; i < corrected_read_amount; i++) {
                    buffer[i] = buffer[i + 1];
                }
                corrected_read_amount -= 1;
                buffer[corrected_read_amount] = 0;
            }

        std::stringstream tmp_str;
        for (unsigned int i = 0; i <= corrected_read_amount; i++) {
            tmp_str << buffer[i];
        }
        str_result += buffer;

        buffer[1024] = {0};
    }

    Logger::Log() << "Message Received. " << str_result.size() << " bytes total." << std::endl;
    return str_result;
}
