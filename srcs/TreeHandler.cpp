#include "../includes/TreeHandler.hpp"

TreeHandler::TreeHandler(std::pair<GameState, Move>& node) {
    _node = node;
}

GameState TreeHandler::GameStateAfterMove(GameState& gameState, Move& move) {
    GameState _gameState = gameState;
    std::vector<Tile> _char = _gameState.getTiles();

    _char[move._characterIdx].setPosition(_gameState.getMap()[_char[move._characterIdx].getPosition()][move._positionIdx]);
    _char[move._characterIdx].setPower(false);
    _gameState.setTiles(_char);
    return _gameState;
}

void TreeHandler::Minimax(std::pair<GameState, Move>& node, int depth, bool isfinal) {
    if (1) // inspector
    { 
        int best = -1000;

        for (auto& _tile : node.first.getTiles()) {
            Move nextMove = { 1, _tile._position, 0, 0, 0, 0 };
        }
    }

        // Traverse all cells 
        /* for (int i = 0; i<3; i++) 
        { 
            for (int j = 0; j<3; j++) 
            { 
                // Check if cell is empty 
                if (board[i][j]=='_') 
                { 
                    // Make the move 
                    board[i][j] = player; 
  
                    // Call minimax recursively and choose 
                    // the maximum value 
                    best = max( best, 
                        minimax(board, depth+1, !isMax) ); 
  
                    // Undo the move 
                    board[i][j] = '_'; 
                } 
            } 
        } 
        return best; 
    } 
  
    // If this minimizer's move 
    else
    { 
        int best = 1000; 
  
        // Traverse all cells 
        for (int i = 0; i<3; i++) 
        { 
            for (int j = 0; j<3; j++) 
            { 
                // Check if cell is empty 
                if (board[i][j]=='_') 
                { 
                    // Make the move 
                    board[i][j] = opponent; 
  
                    // Call minimax recursively and choose 
                    // the minimum value 
                    best = min(best, 
                           minimax(board, depth+1, !isMax)); 
  
                    // Undo the move 
                    board[i][j] = '_'; 
                } 
            } 
        } 
        return best; 
    }  */
}