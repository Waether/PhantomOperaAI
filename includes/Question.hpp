//
// Created by waether on 26/10/19.
//

#ifndef PHANTOMOPERAAI_QUESTION_HPP
#define PHANTOMOPERAAI_QUESTION_HPP

#include <string>
#include "Logger.hpp"

class Question {
public:
    enum Questions {
        CharacterSelection,
        Unknown
    };

    static Questions Evaluate(const std::string &);
};

#endif //PHANTOMOPERAAI_QUESTION_HPP
