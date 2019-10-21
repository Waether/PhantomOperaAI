//
// Created by waether on 21/10/19.
//

#ifndef PHANTOMOPERAAI_PHANTOMAI_HPP
#define PHANTOMOPERAAI_PHANTOMAI_HPP

#include "GameState.hpp"
#include <string>

class FantomAI {
private:
public:
    unsigned int MakeChoice(const std::string & gQuestion, const std::string & gData, const GameState & gState);
};


#endif //PHANTOMOPERAAI_PHANTOMAI_HPP
