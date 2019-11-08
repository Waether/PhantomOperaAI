//
// Created by waether on 05/11/19.
//

#include "TileMove.hpp"

const std::vector<Move> TileMove::getMoveForTile(const Tile &tile, const GameState &gState) {

    std::vector<Move> allmoves;

    switch (tile._color) {
        case Color::Blue:
            allmoves = TileMove::getMoveForBlue(tile, gState);
            break;
        case Color::Grey:
            allmoves = TileMove::getMoveForGrey(tile, gState);
            break;
        case Color::Black:
            allmoves = TileMove::getMoveForBlack(tile, gState);
            break;
        case Color::Red:
            allmoves = TileMove::getMoveForRed(tile, gState);
            break;
        case Color::Purple:
            allmoves = TileMove::getMoveForPurple(tile, gState);
            break;
        case Color::Brown:
            allmoves = TileMove::getMoveForBrown(tile, gState);
            break;
        case Color::Pink:
            allmoves = TileMove::getMoveForPink(tile, gState);
            break;
        case Color::White:
            allmoves = TileMove::getMoveForWhite(tile, gState);
            break;
        case Color::Unknown:
            allmoves.clear();
            break;
    }

    return allmoves;
}

const std::vector<Move> TileMove::getMoveForBlack(const Tile &tile, const GameState &gState) {

    // Can attract everyone one she has moved

    std::vector<Move> moves;
    int current_char = gState.getTileIndexFromTiles(tile._color);

    // for each room that can be reached by moving
    for (int room = 0; room < gState.getMap()[tile._position].size(); room++) {
        if (!gState.pathIsLocked(tile._position, gState.getMap()[tile._position][room])) {
            moves.emplace_back(Move {current_char, // current tile index
                                     room, // room to move
                                     0, // no power
                                     -1, -1, -1, -1, -1}); // ignore
            moves.emplace_back(Move {current_char, // current tile index
                                     room, // room to move
                                     1, // with power
                                     -1, -1, -1, -1, -1}); // ignore

        }
    }

    return moves;
}

const std::vector<Move> TileMove::getMoveForRed(const Tile &tile, const GameState &gState) {

    // Doesn't do anything

    std::vector<Move> moves;
    int current_char = gState.getTileIndexFromTiles(tile._color);

    // for each room that can be reached by moving
    for (int room = 0; room < gState.getMap()[tile._position].size(); room++) {
        if (!gState.pathIsLocked(tile._position, gState.getMap()[tile._position][room])) {
            moves.emplace_back(Move {current_char, // current tile index
                                     room, // room to move
                                     0, // no power
                                     -1, -1, -1, -1, -1}); // ignore
        }
    }

    return moves;
}

const std::vector<Move> TileMove::getMoveForPurple(const Tile &tile, const GameState &gState) {

    // Can Exchange place with someone

    std::vector<Move> moves;
    int current_char = gState.getTileIndexFromTiles(tile._color);

    // for each room that can be reached by moving
    for (int room = 0; room < gState.getMap()[tile._position].size(); room++) {
        if (!gState.pathIsLocked(tile._position, gState.getMap()[tile._position][room])) {
            moves.emplace_back(Move {current_char, // current tile index
                                     room, // room to move
                                     0, // no power
                                     -1, -1, -1, -1, -1}); // ignore
        }
    }

    // No fucking Idea how the server handle this one, Idx for players seems wrong and we don't receive parameters

    return moves;
}

const std::vector<Move> TileMove::getMoveForBrown(const Tile &tile, const GameState &gState) {

    // Can Bring someone with him when he moves (Need to test with multiple peoples)

    std::vector<Move> moves;
    int current_char = gState.getTileIndexFromTiles(tile._color);

    // for each room that can be reached by moving
    for (int room = 0; room < gState.getMap()[tile._position].size(); room++) {
        if (!gState.pathIsLocked(tile._position, gState.getMap()[tile._position][room])) {
            moves.emplace_back(Move {current_char, // current tile index
                                     room, // room to move
                                     0, // no power
                                     -1, -1, -1, -1, -1}); // ignore
            moves.emplace_back(Move {current_char, // current tile index
                                     room, // room to move
                                     1, // with power
                                     -1, -1, -1, -1, -1}); // ignore
        }
    }

    return moves;
}

const std::vector<Move> TileMove::getMoveForBlue(const Tile &tile, const GameState &gState) {

    // Can move the locked path

    std::vector<Move> moves;
    int current_char = gState.getTileIndexFromTiles(tile._color);

    // for each room that can be reached by moving
    for (int room = 0; room < gState.getMap()[tile._position].size(); room++) {
        if (!gState.pathIsLocked(tile._position, gState.getMap()[tile._position][room])) {
            {
                // no power activation
                moves.emplace_back(Move {current_char, // current tile index
                                         room, // room to move
                                         0, // no power
                                         -1, -1, -1, -1, -1}); // ignore

                // power activation
                // for each room existing
                for (int PowerRoom = 0; PowerRoom < 10 /* number of rooms*/; PowerRoom++) {

                    // for each room adjacent to PowerRoom
                    for (int PowerRoomExit = 0; PowerRoomExit < gState.getMap()[PowerRoom].size(); PowerRoomExit++) {
                        moves.emplace_back(Move {current_char, // current tile index
                                                 room, // room to move
                                                 1, // activate power
                                                 -1, // ignore
                                                 PowerRoomExit, // end room for power
                                                 PowerRoom, // start room for power
                                                 -1, -1}); // ignore
                    }
                }
            }
        }
    }

    return moves;
}

const std::vector<Move> TileMove::getMoveForGrey(const Tile &tile, const GameState &gState) {

    // Can move shadow room

    std::vector<Move> moves;
    int current_char = gState.getTileIndexFromTiles(tile._color);

    // for each room that can be reached by moving
    for (int room = 0; room < gState.getMap()[tile._position].size(); room++) {
        if (!gState.pathIsLocked(tile._position, gState.getMap()[tile._position][room])) {
            {
                // no power activation
                moves.emplace_back(Move {current_char, // current tile index
                                         room, // room to move
                                         0, // no power
                                         -1, -1, -1, -1, -1}); // ignore

                // power activation
                // for each room existing
                for (int handlePower = 0; handlePower < 10 /* number of rooms*/; handlePower++) {
                    moves.emplace_back(Move {current_char, // current tile index
                                             room, // room to move
                                             1, // activate power
                                             handlePower, // power room index
                                             -1, -1, -1, -1}); // ignore
                }
            }
        }
    }

    return moves;
}

const std::vector<Move> TileMove::getMoveForPink(const Tile &tile, const GameState &gState) {

    // Can move via pink path

    std::vector<Move> moves;
    int current_char = gState.getTileIndexFromTiles(tile._color);

    // for each room that can be reached by moving
    for (int room = 0; room < gState.getPinkMap()[tile._position].size(); room++) {
        if (!gState.pathIsLocked(tile._position, gState.getPinkMap()[tile._position][room])) {
            moves.emplace_back(Move {current_char, // current tile index
                                     room, // room to move
                                     -1, -1, -1, -1, -1, -1}); // ignore
        }
    }

    return moves;
}

const std::vector<Move> TileMove::getMoveForWhite(const Tile &tile, const GameState &gState) {

    // Move other peoples once it has moved

    std::vector<Move> moves;
    int current_char = gState.getTileIndexFromTiles(tile._color);

    // for each room that can be reached by moving
    for (int room = 0; room < gState.getMap()[tile._position].size(); room++) {
        if (!gState.pathIsLocked(tile._position, gState.getMap()[tile._position][room])) {
            {
                // no power activation
                moves.emplace_back(Move {current_char, // current tile index
                                         room, // room to move
                                         0, // no power
                                         -1, -1, -1, -1, -1}); // ignore

                // power activation
                // for each rooms that can be reached once the caracter has moved
                for (int roomTargetIdx = 0; roomTargetIdx < gState.getMap()[room].size(); roomTargetIdx++) {
                    moves.emplace_back(Move {current_char, // current tile index
                                             room, // room to move
                                             1, // activate power
                                             -1, -1, -1, -1, // ignore
                                             roomTargetIdx}); // room where peoples will move once the char has moved
                }
            }
        }
    }

    return moves;
}
