#include "../includes/TreeHandler.hpp"

TreeHandler::TreeHandler() {}

GameState TreeHandler::GameStateAfterMove(GameState& gameState, const Move& move) {
    GameState _gameState = gameState;
    std::vector<Tile> _tiles = _gameState.getTiles();
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

Move TreeHandler::GetBestMove(GameState& gameState) {
    int bestValue = 0;
    int currentValue = 0;
    Move bestMove;
    TileMove _tileMove;

    for (auto& _tile : gameState.getTiles()) {
        for (auto& _move : _tileMove.getMoveForTile(_tile, gameState)) {
            currentValue = Minimax({gameState, _move});
            if (std::abs(currentValue) > std::abs(bestValue)) {
                bestValue = currentValue;
                bestMove = _move;
            }
        }
    }
    return bestMove;
}

int TreeHandler::Minimax(std::pair<GameState, Move> node) {
    if (node.first.getTiles().size() == 0) {
        BoardScorer scorer(node.first);
        if (node.first.getCurrentPlayer() == 1)
            return scorer.EvaluateInspector();
        if (node.first.getCurrentPlayer() == 0)
            return scorer.EvaluateGhost();
    }

    TileMove _tileMove;
    if (node.first.getCurrentPlayer() == 1) { // inspector
        int best = -1000;
        for (auto& _tile : node.first.getTiles()) { 
            /* GameState saveState = node.first; */
            for (auto& _move : _tileMove.getMoveForTile(_tile, node.first)) {
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
            for (auto& _move : _tileMove.getMoveForTile(_tile, node.first)) {
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