#ifndef PHANTOMOPERAAI_TREEHANDLER_HPP
#define PHANTOMOPERAAI_TREEHANDLER_HPP

#include "GameState.hpp"
#include "Move.hpp"

class TreeHandler {
private:
    std::pair<GameState, Move> _node;
public:
    TreeHandler(std::pair<GameState, Move>&);
    GameState GameStateAfterMove(GameState&, Move&);
    void Minimax(std::pair<GameState, Move>&, int, bool);
};

#endif //PHANTOMOPERAAI_TREEHANDLER_HPP