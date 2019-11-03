//
// Created by waether on 20/10/19.
//

#ifndef C_NET_LOGGER_HPP
#define C_NET_LOGGER_HPP

# define DEBUG_MODE true

#include <iostream>

class Logger {
public:
    static std::ostream & Log();
    static std::ostream & Debug();
    static std::ostream & Error();
};

#endif //C_NET_LOGGER_HPP

