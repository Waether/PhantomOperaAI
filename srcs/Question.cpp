//
// Created by waether on 26/10/19.
//

#include "Question.hpp"

Question::Questions Question::Evaluate(const std::string &qst) {

    Logger::Debug() << "Evaluating Question : " << qst << std::endl;

    if (qst == "select character")
        return Question::CharacterSelection;

    return Question::Unknown;
}
