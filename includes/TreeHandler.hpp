#ifndef PHANTOMOPERAAI_TREEHANDLER_HPP
#define PHANTOMOPERAAI_TREEHANDLER_HPP

#include "BoardScorer.hpp"
#include "GameState.hpp"
#include "Move.hpp"
#include "CharacterMove.hpp"

class TreeHandler {
public:
    TreeHandler() = default;
    GameState GameStateAfterMove(GameState&, const Move&);
    std::vector<Character> getTilesToPlay(GameState&);
    int Minimax(std::pair<GameState, Move>);
    Move GetBestMove(GameState&, int);
};

#endif //PHANTOMOPERAAI_TREEHANDLER_HPP