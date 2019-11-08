#ifndef PHANTOMOPERAAI_TREEHANDLER_HPP
#define PHANTOMOPERAAI_TREEHANDLER_HPP

#include "TileMove.hpp"
#include "BoardScorer.hpp"
#include "GameState.hpp"
#include "Move.hpp"

class TreeHandler {
private:
    std::pair<GameState, Move> _node;
public:
    TreeHandler(std::pair<GameState, Move>&);
    GameState GameStateAfterMove(GameState&, const Move&);
    std::vector<Tile> getTilesToPlay(GameState&);
    int Minimax(std::pair<GameState, Move>&, int);
};

#endif //PHANTOMOPERAAI_TREEHANDLER_HPP