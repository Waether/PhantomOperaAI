#ifndef PHANTOMOPERAAI_TREEHANDLER_HPP
#define PHANTOMOPERAAI_TREEHANDLER_HPP

#include "TileMove.hpp"
#include "BoardScorer.hpp"
#include "GameState.hpp"
#include "Move.hpp"

class TreeHandler {
public:
    TreeHandler() = default;
    GameState GameStateAfterMove(GameState&, const Move&);
    std::vector<Tile> getTilesToPlay(GameState&);
    int Minimax(std::pair<GameState, Move>);
    Move GetBestMove(GameState&);
};

#endif //PHANTOMOPERAAI_TREEHANDLER_HPP