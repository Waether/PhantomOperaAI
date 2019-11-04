//
// Created by waether on 21/10/19.
//


#include "GameState.hpp"

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

                _nb_tour = it.value();
                Logger::Log() << '\t' << "Turn n°" << _nb_tour << std::endl;

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
                    Tile tmp(cit.value());
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

const int &GameState::getShadow() {
    return _shadow;
}

const int &GameState::getCarottaPosition() {
    return _carlotta_position;
}

const int &GameState::getNbTour() {
    return _nb_tour;
}

const int &GameState::getExit() {
    return _exit;
}

const std::string &GameState::getFantom() {
    return _fantom;
}

const std::pair<int, int> &GameState::getBlocked() {
    return _blocked;
}

const std::vector<Character> &GameState::getCharacters() {
    return _characters;
}

const std::vector<Tile> &GameState::getTiles() {
    return _tiles;
}

const int GameState::getCurrentPlayer() {
    int turn = (_nb_tour % 8) + 1;

    switch (turn) {
        case (1, 4, 6, 7) :
            return 1;
        case (2, 3, 5, 8) :
            return 0;
    }
}
