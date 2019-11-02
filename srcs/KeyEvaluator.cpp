//
// Created by waether on 21/10/19.
//

#include "KeyEvaluator.hpp"

KeyEvaluator::Type KeyEvaluator::Evaluate(const std::string & key) {

    // Main Parsing

    if (key == "question type")
        return KeyEvaluator::Question;
    if (key == "data")
        return KeyEvaluator::Data;
    if (key == "game state")
        return KeyEvaluator::GameState;

    // GameState Parsing

    if (key == "blocked")
        return KeyEvaluator::gStateBlocked;
    if (key == "characters")
        return KeyEvaluator::gStateCharacters;
    if (key == "exit")
        return KeyEvaluator::gStateExit;
    if (key == "fantom")
        return KeyEvaluator::gStateFantom;
    if (key == "num_tour")
        return KeyEvaluator::gStateNumberTour;
    if (key == "position_carlotta")
        return KeyEvaluator::gStateCarlotta;
    if (key == "shadow")
        return KeyEvaluator::gStateShadow;
    if (key == "active tiles")
        return KeyEvaluator::gStateTiles;

    return KeyEvaluator::Unknown;
}
