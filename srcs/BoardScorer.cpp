#include "../includes/BoardScorer.hpp"

BoardScorer::BoardScorer() {}

BoardScorer::BoardScorer(GameState& gameState) {
    setGameState(gameState);
}

void BoardScorer::setGameState(GameState& gameState) {
    _gameState = gameState;
    _scoreGhost = 0;
    _scoreInspector = 0;
    for (auto& _character : _gameState.getCharacters()) {
        if (_charactersPosition.find(_character._position) != _charactersPosition.end())
            _charactersPosition[_character._position]++;
    }
    _isSet = true;
}

int BoardScorer::EvaluateGhost() {
    if (!_isSet)
        return;
    return _scoreGhost = 0;
}

int BoardScorer::EvaluateInspector() {
    if (!_isSet)
        return;
    return _scoreInspector = 0;
}

std::pair<int, int> BoardScorer::EvaluateBoard() {
    if (!_isSet)
        return;
    return std::pair<int, int>(EvaluateGhost(), EvaluateInspector());
}

int BoardScorer::EvaluateGhost(GameState& gameState) {
    if (!_isSet)
        setGameState(gameState);
    return _scoreGhost = 0;
}

int BoardScorer::EvaluateInspector(GameState& gameState) {
    if (!_isSet)
        setGameState(gameState);
    return _scoreInspector = 0;
}

std::pair<int, int> BoardScorer::EvaluateBoard(GameState& gameState) {
    if (!_isSet)
        setGameState(gameState);
    return std::pair<int, int>(EvaluateGhost(), EvaluateInspector());
}

bool BoardScorer::IsGhostHidden() {
    int _ghostPosition;
    for (auto &_character : _gameState.getCharacters()) {
        if (_character._color == Color::Evaluate(_gameState.getFantom())) {
            _ghostPosition = _character._position;
        }
    }
    if (_charactersPosition[_ghostPosition] == 1
        || _charactersPosition[_ghostPosition] == _gameState.getShadow())
        return true;
    return false;
}

int BoardScorer::GetNumberOfHiddenCharacter() {
    int _hidden = 0;

    if (_charactersPosition.find(_gameState.getShadow()) != _charactersPosition.end())
        _hidden += _charactersPosition[_gameState.getShadow()];
    for (auto& _position : _charactersPosition) {
        if (_position.second == 1)
            _hidden++;
    }

    return _hidden;
}

int BoardScorer::GetNumberOfVisibleCharacter() {
    return 8 - GetNumberOfHiddenCharacter();
}
