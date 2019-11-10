#include "../includes/BoardScorer.hpp"

BoardScorer::BoardScorer() {
    bool _isSet = false;
}

BoardScorer::BoardScorer(const GameState& gameState) {
    bool _isSet = false;
    setGameState(gameState);
}

void BoardScorer::setGameState(const GameState& gameState) {
    _gameState = gameState;
    _scoreGhost = 0;
    _scoreInspector = 0;
    for (auto& _character : _gameState.getCharacters()) {
        _charactersPosition[_character._position].emplace_back(_character);
    }
    _isSet = true;
}

int BoardScorer::EvaluateGhost() {
    if (!_isSet)
        throw BoardException::GameStateInit();
    int _score = 0;

    if (IsGhostHidden()) {
        _score = -(GetNumberOfSuspectCharacters() * 20) + (GetNumberOfVisibleSuspectCharacters() * 20);    
    }
    else {
        _score = -(GetNumberOfSuspectCharacters() * 15) + (GetNumberOfHiddenSuspectCharacters() * 10);
    }

    return _score;
}

int BoardScorer::EvaluateInspector() {
    if (!_isSet)
        throw BoardException::GameStateInit();
    int _score = 0;


    _score = 100 - 10 * std::abs(GetNumberOfHiddenSuspectCharacters() - GetNumberOfVisibleSuspectCharacters());
    if (GetNumberOfHiddenSuspectCharacters() == GetNumberOfSuspectCharacters())
        _score = -20;

    Logger::Debug() << "Score inspector : " << _score << std::endl;
    return _score;
}

std::pair<int, int> BoardScorer::EvaluateBoard() {
    if (!_isSet)
        throw BoardException::GameStateInit();
    return {EvaluateGhost(), EvaluateInspector()};
}

int BoardScorer::EvaluateGhost(const GameState& gameState) {
    if (!_isSet)
        setGameState(gameState);
    return _scoreGhost = 0;
}

int BoardScorer::EvaluateInspector(const GameState& gameState) {
    if (!_isSet)
        setGameState(gameState);
    return _scoreInspector = 0;
}

std::pair<int, int> BoardScorer::EvaluateBoard(const GameState& gameState) {
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
    if (_charactersPosition[_ghostPosition].size() == 1
        || _ghostPosition == _gameState.getShadow())
        return true;
    return false;
}

int BoardScorer::GetNumberOfSuspectCharacters() {
    int _suspects = 0;
    for (auto &_character : _gameState.getCharacters()) {
        if (_character._suspect) {
            _suspects++;
        }
    }
    return _suspects;
}

int BoardScorer::GetNumberOfNonSuspectCharacters() {
    return 8 - GetNumberOfSuspectCharacters();
}

int BoardScorer::GetNumberOfHiddenCharacters() {
    int _hidden = 0;

    if (_charactersPosition.find(_gameState.getShadow()) != _charactersPosition.end())
        _hidden += _charactersPosition[_gameState.getShadow()].size();
    for (auto& _position : _charactersPosition) {
        if (_position.second.size() == 1
            && _position.first != _gameState.getShadow())
            _hidden++;
    }
    return _hidden;
}

int BoardScorer::GetNumberOfHiddenSuspectCharacters() {
    int _hidden = 0;

    if (_charactersPosition.find(_gameState.getShadow()) != _charactersPosition.end()) {
        for (auto& _character : _charactersPosition[_gameState.getShadow()]) {
            if (_character._suspect)
                _hidden++;
        }
    }
    for (auto& _position : _charactersPosition) {
        if (_position.second.size() == 1
            && _position.first != _gameState.getShadow()
            && _position.second[0]._suspect)
            _hidden++;
    }
    return _hidden;
}

int BoardScorer::GetNumberOfVisibleCharacters() {
    return 8 - GetNumberOfHiddenCharacters();
}

// TODO
int BoardScorer::GetNumberOfVisibleSuspectCharacters() {
    int _visibleSuspects = 0;
    
    for (auto& _position : _charactersPosition) {
        if (_position.second.size() > 1
            && _position.first != _gameState.getShadow()) {
            for (auto _character: _position.second) {
                if (_character._suspect)
                    _visibleSuspects++;
            }
        }
    }
    return _visibleSuspects;
}
