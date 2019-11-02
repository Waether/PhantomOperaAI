
#ifndef PHANTOMOPERAAI_BOARDSCORER_HPP
#define PHANTOMOPERAAI_BOARDSCORER_HPP

#include "GameState.hpp"
#include "Logger.hpp"

class BoardScorer {
private:
    bool _isSet = false;
    GameState _gameState;
    int _scoreGhost = 0;
    int _scoreInspector = 0;
    std::map<int, int> _charactersPosition;

public:
    explicit BoardScorer();
    explicit BoardScorer(GameState&);
    void setGameState(GameState&);

    int EvaluateGhost();
    int EvaluateInspector();
    std::pair<int, int>EvaluateBoard();
    int EvaluateGhost(GameState&);
    int EvaluateInspector(GameState&);
    std::pair<int, int>EvaluateBoard(GameState&);

private:
    bool IsGhostHidden();

    int GetNumberOfHiddenCharacter();
    int GetNumberOfVisibleCharacter();
};


#endif //PHANTOMOPERAAI_BOARDSCORER_HPP
