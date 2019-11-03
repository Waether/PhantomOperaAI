
#ifndef PHANTOMOPERAAI_BOARDSCORER_HPP
#define PHANTOMOPERAAI_BOARDSCORER_HPP

#include "BoardException.hpp"

#include "GameState.hpp"
#include "Logger.hpp"

class BoardScorer {
private:
    bool _isSet;
    GameState _gameState;
    int _scoreGhost;
    int _scoreInspector
    std::map<int, int> _charactersPosition;

public:
    explicit BoardScorer();
    explicit BoardScorer(const GameState&);
    void setGameState(const GameState&);

    int EvaluateGhost();
    int EvaluateInspector();
    std::pair<int, int>EvaluateBoard();
    int EvaluateGhost(const GameState&);
    int EvaluateInspector(const GameState&);
    std::pair<int, int>EvaluateBoard(const GameState&);

private:
    bool IsGhostHidden();

    int GetNumberOfHiddenCharacter();
    int GetNumberOfVisibleCharacter();
};


#endif //PHANTOMOPERAAI_BOARDSCORER_HPP
