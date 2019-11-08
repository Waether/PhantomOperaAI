#include "TreeHandler.hpp"

GameState TreeHandler::GameStateAfterMove(GameState& gameState, const Move& move) {
    GameState _gameState = gameState;
    std::vector<Character> _tiles = _gameState.getTiles();
    Color::Colors colorToMove = _tiles[move._characterIdx].getColor();
    _tiles.erase(_tiles.begin() + move._characterIdx);
    _gameState.setTiles(_tiles);
    std::vector<Character> _chars = _gameState.getCharacters();
    for (auto& _char : _chars) {
        if (_char.getColor() == colorToMove) {
            _char.setPosition(_gameState.getMap()[_char.getPosition()][move._positionIdx]);
            _char.setPower(false);
            // handle power for each char
        }
    }
    _gameState.setCharacters(_chars);
    _gameState.setNbTour(_gameState.getNbTour() + 1);
    return _gameState;
}

Move TreeHandler::GetBestMove(GameState& gameState, int player) {
    int _bestValue = 0;
    int _currentValue = 0;
    Move _bestMove = {-1, -1, -1, -1, -1, -1, -1, -1};

    Logger::Debug() << "Starting TreeHandler::GetBestMove ..." << std::endl;

    for (auto& _tile : gameState.getTiles()) {

        Logger::Debug() << "For " << _tile << std::endl;

        for (auto& _move : CharacterMove::getMoveForCharacter(_tile, gameState)) {

            std::pair<GameState, Move> _newNode;
            _newNode.first = GameStateAfterMove(gameState, _move);
            _newNode.second = _move;
            _currentValue = Minimax(_newNode);

            Logger::Debug() << "For move : {" << _move._characterIdx
                            << ", " << _move._powerMoveIdx
                            << ", " << _move._powerRoomIdx
                            << ", " << _move._powerExitIdx
                            << ", " << _move._handlePowerIdx
                            << ", " << _move._activatePowerIdx
                            << ", " << _move._positionIdx
                            << ", " << _move._powerMoveTargetIdx
                            << "} -> Value : " << _currentValue << std::endl;

            if (player == 1 && _currentValue > _bestValue) { // inspector
                _bestValue = _currentValue;
                _bestMove = _move;
            }
            if (player == 0 && _currentValue < _bestValue) { // ghost
                _bestValue = _currentValue;
                _bestMove = _move;
            }
        }
    }

    Logger::Debug() << "TreeHandler::GetBestMove Done." << std::endl;

    Logger::Debug() << "Selected Best move : {" << _bestMove._characterIdx
                    << ", " << _bestMove._powerMoveIdx
                    << ", " << _bestMove._powerRoomIdx
                    << ", " << _bestMove._powerExitIdx
                    << ", " << _bestMove._handlePowerIdx
                    << ", " << _bestMove._activatePowerIdx
                    << ", " << _bestMove._positionIdx
                    << ", " << _bestMove._powerMoveTargetIdx
                    << "}" << std::endl;


    return _bestMove;
}

int TreeHandler::Minimax(std::pair<GameState, Move> node) {
    if (node.first.getTiles().empty()) {
        BoardScorer scorer(node.first);
        if (node.first.getCurrentPlayer() == 1)
            return scorer.EvaluateInspector();
        if (node.first.getCurrentPlayer() == 0)
            return scorer.EvaluateGhost();
    }

    if (node.first.getCurrentPlayer() == 1) { // inspector
        int best = -1000;
        for (auto& _tile : node.first.getTiles()) { 
            /* GameState saveState = node.first; */
            for (auto& _move : CharacterMove::getMoveForCharacter(_tile, node.first)) {
                std::pair<GameState, Move> _newNode;
                _newNode.first = GameStateAfterMove(node.first, _move);
                _newNode.second = _move;
                best = std::max(best, Minimax(_newNode));
                /* node.first = saveState; */
            }
            return best;
        }
    } else if (node.first.getCurrentPlayer() == 0) { // ghost
        int best = 1000;
        for (auto& _tile : node.first.getTiles()) { 
            /* GameState saveState = node.first; */
            for (auto& _move : CharacterMove::getMoveForCharacter(_tile, node.first)) {
                std::pair<GameState, Move> _newNode;
                _newNode.first = GameStateAfterMove(node.first, _move);
                _newNode.second = _move;
                best = std::min(best, Minimax(_newNode));
                /* node.first = saveState; */
            }
            return best;
        }
    }
}