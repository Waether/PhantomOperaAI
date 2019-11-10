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

            switch (_char._color) {
                case Color::Blue:
                    _gameState = MakeMoveForBlue(_char, gameState, move);
                    break;
                case Color::Grey:
                    _gameState = MakeMoveForGrey(_char, gameState, move);
                    break;
                case Color::Black:
                    _gameState = MakeMoveForBlack(_char, gameState, move);
                    break;
                case Color::Red:
                    _gameState = MakeMoveForRed(_char, gameState, move);
                    break;
                case Color::Purple:
                    _gameState = MakeMoveForPurple(_char, gameState, move);
                    break;
                case Color::Brown:
                    _gameState = MakeMoveForBrown(_char, gameState, move);
                    break;
                case Color::Pink:
                    _gameState = MakeMoveForPink(_char, gameState, move);
                    break;
                case Color::White:
                    _gameState = MakeMoveForWhite(_char, gameState, move);
                    break;
                case Color::Unknown:
                    break;
            }
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

    for (auto& _tile : gameState.getTiles()) {

        for (auto& _move : CharacterMove::getMoveForCharacter(_tile, gameState)) {

            std::pair<GameState, Move> _newNode;
            _newNode.first = GameStateAfterMove(gameState, _move);

            _newNode.second = _move;
            _currentValue = Minimax(_newNode, player);

            if (player == 1 && (_currentValue >= _bestValue || _bestMove._positionIdx == -1)) { // inspector
                _bestValue = _currentValue;
                _bestMove = _move;
            }
            if (player == 0 && (_currentValue <= _bestValue || _bestMove._positionIdx == -1)) { // ghost
                _bestValue = _currentValue;
                _bestMove = _move;
            }
        }
    }

    return _bestMove;
}

int TreeHandler::Minimax(std::pair<GameState, Move> node, int player) {
    if (node.first.getTiles().empty()) {
        BoardScorer scorer(node.first);
        if (player == 1) {
            return scorer.EvaluateInspector();
        }
        if (player == 0) {
            return scorer.EvaluateGhost();
        }
    }

    if (node.first.getCurrentPlayer() == 1) { // inspector
        int best = -1000;
        for (auto& _tile : node.first.getTiles()) {
            for (auto& _move : CharacterMove::getMoveForCharacter(_tile, node.first)) {
                std::pair<GameState, Move> _newNode;
                _newNode.first = GameStateAfterMove(node.first, _move);
                _newNode.second = _move;
                best = std::max(best, Minimax(_newNode, player));
            }
            return best;
        }
    } else if (node.first.getCurrentPlayer() == 0) { // ghost
        int best = 1000;
        for (auto& _tile : node.first.getTiles()) {
            for (auto& _move : CharacterMove::getMoveForCharacter(_tile, node.first)) {
                std::pair<GameState, Move> _newNode;
                _newNode.first = GameStateAfterMove(node.first, _move);
                _newNode.second = _move;
                best = std::min(best, Minimax(_newNode, player));
            }
            return best;
        }
    }
}

const GameState TreeHandler::MakeMoveForBlue(const Character &character, const GameState &gState, const Move & move) {
    GameState newgState = gState;

    // Delete char from tiles
    std::vector<Character> _tiles = newgState.getTiles();
    _tiles.erase(_tiles.begin() + move._characterIdx);
    newgState.setTiles(_tiles);

    std::vector<Character> _chars = gState.getCharacters();

//    _char.setPosition(_gameState.getMap()[_char.getPosition()][move._positionIdx]);
//    _gameState.setCharacters(_chars);
//    _gameState.setNbTour(_gameState.getNbTour() + 1);

    return newgState;
}

const GameState TreeHandler::MakeMoveForGrey(const Character &character, const GameState &gState, const Move & move) {
    GameState newgState = gState;

    // Delete char from tiles
    std::vector<Character> _tiles = newgState.getTiles();
    _tiles.erase(_tiles.begin() + move._characterIdx);
    newgState.setTiles(_tiles);

    std::vector<Character> _chars = gState.getCharacters();

//    _char.setPosition(_gameState.getMap()[_char.getPosition()][move._positionIdx]);
//    _gameState.setCharacters(_chars);
//    _gameState.setNbTour(_gameState.getNbTour() + 1);

    return newgState;
}

const GameState TreeHandler::MakeMoveForBlack(const Character &character, const GameState &gState, const Move & move) {
    GameState newgState = gState;

    // Delete char from tiles
    std::vector<Character> _tiles = newgState.getTiles();
    _tiles.erase(_tiles.begin() + move._characterIdx);
    newgState.setTiles(_tiles);

    // Simple move
    std::vector<Character> _chars = newgState.getCharacters();
    for (int i = 0; i <= _chars.size(); i++) {
        if (_chars[i]._color == character._color)
            _chars[i].setPosition(newgState.getMap()[_chars[i].getPosition()][move._positionIdx]);
    }

    // Power

    // End & return
    newgState.setCharacters(_chars);
    newgState.setNbTour(newgState.getNbTour() + 1);

    return newgState;
}

const GameState TreeHandler::MakeMoveForRed(const Character &character, const GameState &gState, const Move & move) {
    GameState newgState = gState;

    // Delete char from tiles
    std::vector<Character> _tiles = newgState.getTiles();
    _tiles.erase(_tiles.begin() + move._characterIdx);
    newgState.setTiles(_tiles);

    // Simple move
    std::vector<Character> _chars = newgState.getCharacters();
    for (int i = 0; i <= _chars.size(); i++) {
        if (_chars[i]._color == character._color)
            _chars[i].setPosition(newgState.getMap()[_chars[i].getPosition()][move._positionIdx]);
    }

    // Power

    // End & return
    newgState.setCharacters(_chars);
    newgState.setNbTour(newgState.getNbTour() + 1);

    return newgState;
}

const GameState TreeHandler::MakeMoveForPurple(const Character &character, const GameState &gState, const Move & move) {
    GameState newgState = gState;

    // Delete char from tiles
    std::vector<Character> _tiles = newgState.getTiles();
    _tiles.erase(_tiles.begin() + move._characterIdx);
    newgState.setTiles(_tiles);

    // Simple move
    std::vector<Character> _chars = newgState.getCharacters();
    for (int i = 0; i <= _chars.size(); i++) {
        if (_chars[i]._color == character._color)
            _chars[i].setPosition(newgState.getMap()[_chars[i].getPosition()][move._positionIdx]);
    }

    // Power

    // End & return
    newgState.setCharacters(_chars);
    newgState.setNbTour(newgState.getNbTour() + 1);

    return newgState;
}

const GameState TreeHandler::MakeMoveForBrown(const Character &character, const GameState &gState, const Move & move) {
    GameState newgState = gState;

    // Delete char from tiles
    std::vector<Character> _tiles = newgState.getTiles();
    _tiles.erase(_tiles.begin() + move._characterIdx);
    newgState.setTiles(_tiles);

    // Simple move
    std::vector<Character> _chars = newgState.getCharacters();
    for (int i = 0; i <= _chars.size(); i++) {
        if (_chars[i]._color == character._color)
            _chars[i].setPosition(newgState.getMap()[_chars[i].getPosition()][move._positionIdx]);
    }

    // Power

    // End & return
    newgState.setCharacters(_chars);
    newgState.setNbTour(newgState.getNbTour() + 1);

    return newgState;
}

const GameState TreeHandler::MakeMoveForPink(const Character &character, const GameState &gState, const Move & move) {
    GameState newgState = gState;

    // Delete char from tiles
    std::vector<Character> _tiles = newgState.getTiles();
    _tiles.erase(_tiles.begin() + move._characterIdx);
    newgState.setTiles(_tiles);

    // Simple move
    std::vector<Character> _chars = newgState.getCharacters();
    for (int i = 0; i <= _chars.size(); i++) {
        if (_chars[i]._color == character._color)
            _chars[i].setPosition(newgState.getMap()[_chars[i].getPosition()][move._positionIdx]);
    }

    // Power

    // End & return
    newgState.setCharacters(_chars);
    newgState.setNbTour(newgState.getNbTour() + 1);

    return newgState;
}

const GameState TreeHandler::MakeMoveForWhite(const Character &character, const GameState &gState, const Move & move) {
    GameState newgState = gState;

    // Delete char from tiles
    std::vector<Character> _tiles = newgState.getTiles();
    _tiles.erase(_tiles.begin() + move._characterIdx);
    newgState.setTiles(_tiles);

    // Simple move
    std::vector<Character> _chars = newgState.getCharacters();
    for (int i = 0; i <= _chars.size(); i++) {
        if (_chars[i]._color == character._color)
            _chars[i].setPosition(newgState.getMap()[_chars[i].getPosition()][move._positionIdx]);
    }

    // Power

    // End & return
    newgState.setCharacters(_chars);
    newgState.setNbTour(newgState.getNbTour() + 1);

    return newgState;
}
