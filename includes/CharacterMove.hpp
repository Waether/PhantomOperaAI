//
// Created by waether on 05/11/19.
//

#ifndef PHANTOMOPERAAI_CHARACTERMOVE_HPP
#define PHANTOMOPERAAI_CHARACTERMOVE_HPP

#include <vector>
#include "Move.hpp"
#include "GameState.hpp"

class CharacterMove {

    static const std::vector<Move> & getMoveForCharacter(const Character & character, const GameState & gState);

    static const std::vector<Move> & getMoveForBlue(const GameState & gState);
    static const std::vector<Move> & getMoveForGrey(const GameState & gState);
    static const std::vector<Move> & getMoveForBlack(const GameState & gState);
    static const std::vector<Move> & getMoveForRed(const GameState & gState);
    static const std::vector<Move> & getMoveForPurple(const GameState & gState);
    static const std::vector<Move> & getMoveForBrown(const GameState & gState);
    static const std::vector<Move> & getMoveForPink(const GameState & gState);
    static const std::vector<Move> & getMoveForWhite(const GameState & gState);

    static const std::vector<Move> & getBaseMove(const Character & character, const GameState & gState);
};


#endif //PHANTOMOPERAAI_CHARACTERMOVE_HPP
