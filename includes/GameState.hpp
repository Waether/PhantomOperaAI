//
// Created by waether on 21/10/19.
//

#ifndef PHANTOMOPERAAI_GAMESTATE_HPP
#define PHANTOMOPERAAI_GAMESTATE_HPP

#include <string>
#include "Logger.hpp"
#include "nlohmann/json.hpp"
#include "KeyEvaluator.hpp"
#include "Character.hpp"
#include "Tiles.hpp"

class GameState {
private:
    std::vector<Character> _characters;
    std::vector<Tile> _tiles;
    std::pair<int, int> _blocked;
    std::string _fantom;
    int _exit;
    int _nb_tour;
    int _carlotta_position;
    int _shadow;
    std::vector<std::vector<unsigned int>> _map;
    std::vector<std::vector<unsigned int>> _pink_map;

public:
    GameState();

    void Update(nlohmann::json &);

    const std::vector<Tile> & getTiles();
    const std::vector<Character> & getCharacters();
    const std::pair<int, int> & getBlocked();
    const std::string & getFantom();
    const int & getExit();
    const int & getNbTour();
    const int & getCarlottaPosition();
    const int & getShadow();
    const int getCurrentPlayer();
    const std::vector<std::vector<unsigned int>> & getMap();
    const std::vector<std::vector<unsigned int>> & getPinkMap();

    void setCharacters(const std::vector<Character> &_characters);
    void setTiles(const std::vector<Tile> &_tiles);
    void setBlocked(const std::pair<int, int> &_blocked);
    void setFantom(const std::string &_fantom);
    void setExit(int _exit);
    void setNbTour(int _nb_tour);
    void setCarlottaPosition(int _carlotta_position);
    void setShadow(int _shadow);

};


#endif //PHANTOMOPERAAI_GAMESTATE_HPP
