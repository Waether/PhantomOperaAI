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
    const GameState MakegetMoveForGrey(const Character & character, const GameState & gState, const Move & move);
    const GameState MakegetMoveForBlack(const Character & character, const GameState & gState, const Move & move);
    const GameState MakegetMoveForRed(const Character & character, const GameState & gState, const Move & move);
    const GameState MakegetMoveForPurple(const Character & character, const GameState & gState, const Move & move);
    const GameState MakegetMoveForBrown(const Character & character, const GameState & gState, const Move & move);
    const GameState MakegetMoveForPink(const Character & character, const GameState & gState, const Move & move);
    const GameState MakegetMoveForWhite(const Character & character, const GameState & gState, const Move & move);
};

#endif //PHANTOMOPERAAI_TREEHANDLER_HPP