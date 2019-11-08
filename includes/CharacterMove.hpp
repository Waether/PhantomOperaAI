//
// Created by waether on 05/11/19.
//

#ifndef PHANTOMOPERAAI_CHARACTERMOVE_HPP
#define PHANTOMOPERAAI_CHARACTERMOVE_HPP

#include <vector>
#include "Move.hpp"
#include "GameState.hpp"

class CharacterMove {
public:
    static const std::vector<Move> getMoveForCharacter(const Character & character, const GameState & gState);

    static const std::vector<Move> getMoveForBlue(const Character & character, const GameState & gState);
    static const std::vector<Move> getMoveForGrey(const Character & character, const GameState & gState);
    static const std::vector<Move> getMoveForBlack(const Character & character, const GameState & gState);
    static const std::vector<Move> getMoveForRed(const Character & character, const GameState & gState);
    static const std::vector<Move> getMoveForPurple(const Character & character, const GameState & gState);
    static const std::vector<Move> getMoveForBrown(const Character & character, const GameState & gState);
    static const std::vector<Move> getMoveForPink(const Character & character, const GameState & gState);
    static const std::vector<Move> getMoveForWhite(const Character & character, const GameState & gState);

};


#endif //PHANTOMOPERAAI_CHARACTERMOVE_HPP
