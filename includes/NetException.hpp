//
// Created by waether on 21/10/19.
//

#ifndef C_NET_NETEXCEPTION_HPP
#define C_NET_NETEXCEPTION_HPP

#include <exception>

namespace NetException {

    struct SocketInit : public std::exception
    {
        const char * what () const throw () override {
            return "Socket Failed to Init.";
        }
    };

    struct ConFailed : public std::exception
    {
        const char * what () const throw () override {
            return "Socket Connection Failed.";
        }
    };

    struct SendFailed : public std::exception
    {
        const char * what () const throw () override {
            return "Failed to Send Message.";
        }
    };

    struct PearDisconnected : public std::exception
    {
        const char * what () const throw () override {
            return "Peer Disconnected.";
        }
    };

    struct ConInterrupted : public std::exception
    {
        const char * what () const throw () override {
            return "Connection to Peer Interrupted.";
        }
    };

};


#endif //C_NET_NETEXCEPTION_HPP
