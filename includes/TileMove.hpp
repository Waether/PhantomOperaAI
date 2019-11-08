//
// Created by waether on 05/11/19.
//

#ifndef PHANTOMOPERAAI_CHARACTERMOVE_HPP
#define PHANTOMOPERAAI_CHARACTERMOVE_HPP

#include <vector>
#include "Move.hpp"
#include "GameState.hpp"

class TileMove {
public:
    static const std::vector<Move> getMoveForTile(const Tile & tile, const GameState & gState);

    static const std::vector<Move> getMoveForBlue(const Tile & tile, const GameState & gState);
    static const std::vector<Move> getMoveForGrey(const Tile & tile, const GameState & gState);
    static const std::vector<Move> getMoveForBlack(const Tile & tile, const GameState & gState);
    static const std::vector<Move> getMoveForRed(const Tile & tile, const GameState & gState);
    static const std::vector<Move> getMoveForPurple(const Tile & tile, const GameState & gState);
    static const std::vector<Move> getMoveForBrown(const Tile & tile, const GameState & gState);
    static const std::vector<Move> getMoveForPink(const Tile & tile, const GameState & gState);
    static const std::vector<Move> getMoveForWhite(const Tile & tile, const GameState & gState);

};


#endif //PHANTOMOPERAAI_CHARACTERMOVE_HPP
