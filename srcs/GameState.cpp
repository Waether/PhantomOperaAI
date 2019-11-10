//
// Created by waether on 21/10/19.
//


#include "GameState.hpp"

GameState::GameState() {
    _map = {{1, 4},
            {0, 2},
            {1, 3},
            {2, 7},
            {0, 5, 8},
            {4, 6},
            {5, 7},
            {3, 6, 9},
            {4, 9},
            {7, 8}
    };

    _pink_map = {{1, 4},
                 {0, 2, 5, 7},
                 {1, 3, 6},
                 {2, 7},
                 {0, 5, 8, 9},
                 {4, 6, 1, 8},
                 {5, 7, 2, 9},
                 {3, 6, 9, 1},
                 {4, 9, 5},
                 {7, 8, 4, 6}
    };

    _nb_tour = 0;
}

void GameState::Update(nlohmann::json & newGameState) {

    Logger::Log() << "Updating GameState ..." << std::endl;

    _characters.clear();
    _tiles.clear();

    for (nlohmann::json::iterator it = newGameState.begin(); it != newGameState.end(); ++it) {

        switch (KeyEvaluator::Evaluate(it.key())) {
            case KeyEvaluator::gStateBlocked :

                _blocked.first = it.value()[0];
                _blocked.second = it.value()[1];
                Logger::Log() << '\t' << "Path is blocked between tile n°" << _blocked.first
                              << " and n°" << _blocked.second << std::endl;
                break;

            case KeyEvaluator::gStateCharacters :

                for (nlohmann::json::iterator cit = it.value().begin(); cit != it.value().end(); ++cit) {
                    Character tmp(cit.value());
                    _characters.emplace_back(tmp);
                }

                Logger::Log() << "\tCharacter List :" << std::endl;
                for (auto &_character : _characters) {
                    Logger::Log() << "\t  " << _character << std::endl;
                }

                break;

            case KeyEvaluator::gStateExit :

                _exit = it.value();
                Logger::Log() << '\t' << "Exit : " << _exit << std::endl;

                break;

            case KeyEvaluator::gStateFantom :

                _fantom = it.value();
                Logger::Log() << '\t' << "Fantom is : " << _fantom << std::endl;

                break;

            case KeyEvaluator::gStateNumberTour :

//                _nb_tour = it.value();
//                Logger::Log() << '\t' << "Turn n°" << _nb_tour << std::endl;

                break;

            case KeyEvaluator::gStateCarlotta :

                _carlotta_position = it.value();
                Logger::Log() << '\t' << "Carlotta is in position : " << _carlotta_position << std::endl;

                break;

            case KeyEvaluator::gStateShadow :

                _shadow = it.value();
                Logger::Log() << '\t' << "Shadow is in tile : " << _shadow << std::endl;

                break;

            case KeyEvaluator::gStateTiles :

                for (nlohmann::json::iterator cit = it.value().begin(); cit != it.value().end(); ++cit) {
                    Character tmp(cit.value());
                    _tiles.emplace_back(tmp);
                }

                Logger::Log() << "\tTile List :" << std::endl;
                for (auto &_tile : _tiles) {
                    Logger::Log() << "\t  " << _tile << std::endl;
                }

                break;

            default :
                Logger::Error() << '\t' << "Found Unknown Key : " << it.key() << std::endl;
                Logger::Error() << '\t' << it.value() << std::endl;
                break;
        }
    }

    Logger::Log() << "GameState Updated." << std::endl;
}

const int &GameState::getShadow() const {
    return _shadow;
}

const int &GameState::getCarlottaPosition() const {
    return _carlotta_position;
}

const int &GameState::getNbTour() const {
    return _nb_tour;
}

const int &GameState::getExit() const {
    return _exit;
}

const std::string &GameState::getFantom() const {
    return _fantom;
}

const std::pair<int, int> &GameState::getBlocked() const {
    return _blocked;
}

const std::vector<Character> &GameState::getCharacters() const {
    return _characters;
}

const std::vector<Character> &GameState::getTiles() const {
    return _tiles;
}

const int GameState::getCurrentPlayer() const {
    int turn = ((_nb_tour - 1) % 8) + 1;

    switch (turn) {
        case 1 :
            return 1;
        case 4 :
            return 1;
        case 6 :
            return 1;
        case 7 :
            return 1;
        case 2 :
            return 0;
        case 3 :
            return 0;
        case 5 :
            return 0;
        case 8 :
            return 0;    
    }
}

const std::vector<std::vector<int>> & GameState::getMap() const {
    return _map;
}

const std::vector<std::vector<int>> & GameState::getPinkMap() const {
    return _pink_map;
}

void GameState::setCharacters(const std::vector<Character> &characters) {
    _characters = characters;
}

void GameState::setTiles(const std::vector<Character> &tiles) {
    _tiles = tiles;
}

void GameState::setBlocked(const std::pair<int, int> &blocked) {
    _blocked = blocked;
}

void GameState::setFantom(const std::string &fantom) {
    _fantom = fantom;
}

void GameState::setExit(int exit) {
    _exit = exit;
}

void GameState::setNbTour(int nb_tour) {
    _nb_tour = nb_tour;
}

void GameState::setCarlottaPosition(int carlotta_position) {
    _carlotta_position = carlotta_position;
}

void GameState::setShadow(int shadow) {
    _shadow = shadow;
}

bool GameState::pathIsLocked(int first, int second) const {
    return (_blocked.first == first && _blocked.second == second) ||
           (_blocked.first == second && _blocked.second == first);
}

const int GameState::getCharacterIndexFromTiles(Color::Colors clr) const {

    for (unsigned int i = 0; i <= _tiles.size(); i++) {
        if (_tiles[i]._color == clr)
            return i;
    }

    return 0;
}

const int GameState::getTileIndexFromTiles(Color::Colors clr) const {

    for (unsigned int i = 0; i <= _tiles.size(); i++) {
        if (_tiles[i]._color == clr)
            return i;
    }

    return 0;
}
