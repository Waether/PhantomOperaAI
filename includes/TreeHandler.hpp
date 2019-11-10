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
    int Minimax(std::pair<GameState, Move>, int);
    Move GetBestMove(GameState&, int);

    const GameState MakeMoveForBlue(const Character & character, const GameState & gState, const Move & move);
    const GameState MakeMoveForGrey(const Character & character, const GameState & gState, const Move & move);
    const GameState MakeMoveForBlack(const Character & character, const GameState & gState, const Move & move);
    const GameState MakeMoveForRed(const Character & character, const GameState & gState, const Move & move);
    const GameState MakeMoveForPurple(const Character & character, const GameState & gState, const Move & move);
    const GameState MakeMoveForBrown(const Character & character, const GameState & gState, const Move & move);
    const GameState MakeMoveForPink(const Character & character, const GameState & gState, const Move & move);
    const GameState MakeMoveForWhite(const Character & character, const GameState & gState, const Move & move);
};

#endif //PHANTOMOPERAAI_TREEHANDLER_HPP