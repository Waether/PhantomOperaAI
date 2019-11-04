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

public:
    void Update(nlohmann::json &);

    const std::vector<Tile> & getTiles();
    const std::vector<Character> & getCharacters();
    const std::pair<int, int> & getBlocked();
    const std::string & getFantom();
    const int & getExit();
    const int & getNbTour();
    const int & getCarottaPosition();
    const int & getShadow();
    const int getCurrentPlayer();

};


#endif //PHANTOMOPERAAI_GAMESTATE_HPP
