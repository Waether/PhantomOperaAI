//
// Created by waether on 21/10/19.
//

#include "KeyEvaluator.hpp"

KeyEvaluator::Type KeyEvaluator::Evaluate(const std::string & key) {
    if (key == "question type")
        return KeyEvaluator::Question;
    if (key == "data")
        return KeyEvaluator::Data;
    if (key == "game state")
        return KeyEvaluator::GameState;
    return KeyEvaluator::Unknown;
}
