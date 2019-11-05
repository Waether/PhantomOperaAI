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
#include "Tile.hpp"

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
    std::vector<std::vector<int>> _map;
    std::vector<std::vector<int>> _pink_map;

public:
    GameState();

    void Update(nlohmann::json &);

    const std::vector<Tile> & getTiles() const;
    const std::vector<Character> & getCharacters() const;
    const std::pair<int, int> & getBlocked() const;
    const std::string & getFantom() const;
    const int & getExit() const;
    const int & getNbTour() const;
    const int & getCarlottaPosition() const;
    const int & getShadow() const;
    const int getCurrentPlayer() const;
    const std::vector<std::vector<int>> & getMap() const;
    const std::vector<std::vector<int>> & getPinkMap() const;

    void setCharacters(const std::vector<Character> &);
    void setTiles(const std::vector<Tile> &);
    void setBlocked(const std::pair<int, int> &);
    void setFantom(const std::string &);
    void setExit(int);
    void setNbTour(int);
    void setCarlottaPosition(int);
    void setShadow(int);

    const int getCharacterIndexFromTiles(Color::Colors) const;
    bool pathIsLocked(int, int) const;
};

#endif //PHANTOMOPERAAI_GAMESTATE_HPP
