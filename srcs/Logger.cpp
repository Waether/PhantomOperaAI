//
// Created by waether on 20/10/19.
//

#include <Logger.hpp>

std::ostream & Logger::Log() {
    if (!DEBUG_MODE)
        std::cout.clear();
    return std::cout << "\033[39m" << "[MSG] ";
}

std::ostream & Logger::Debug() {
    if (!DEBUG_MODE)
        std::cout.setstate(std::ios_base::badbit);
    return std::cout << "\033[34m" << "[DBG] ";
}

std::ostream & Logger::Error() {
    return std::cerr << "\033[31m" << "[ERR] ";
}
