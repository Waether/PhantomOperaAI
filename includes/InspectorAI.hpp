//
// Created by waether on 21/10/19.
//

#ifndef PHANTOMOPERAAI_DETECTIVEAI_HPP
#define PHANTOMOPERAAI_DETECTIVEAI_HPP

#include "GameState.hpp"
#include "Question.hpp"
#include <string>

class InspectorAI {
private:
public:
    unsigned int MakeChoice(const Question::Questions & gQuestion, const std::string & gData, const GameState & gState);
};


#endif //PHANTOMOPERAAI_DETECTIVEAI_HPP
