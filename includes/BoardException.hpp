//
// Created by waether on 21/10/19.
//

#ifndef C_BOARDEXCEPTION_HPP
#define C_BOARDEXCEPTION_HPP

#include <exception>

namespace BoardException {

    struct GameStateInit : public std::exception
    {
        const char * what () const throw () override {
            return "GameState is not Init.";
        }
    };
};


#endif //C_BOARDEXCEPTION_HPP
