//
// Created by waether on 26/10/19.
//

#ifndef PHANTOMOPERAAI_TILE_HPP
#define PHANTOMOPERAAI_TILE_HPP

#include "Color.hpp"
#include "nlohmann/json.hpp"
#include "Logger.hpp"

class Tile {
public:
    Color::Colors _color;
    int _position;
    bool _power;
    bool _suspect;

public:
    explicit Tile(nlohmann::json);

    const Color::Colors & getColor();
    const int & getPosition();
    const bool & getPower();
    const bool & isSuspect();

    friend std::ostream & operator<<(std::ostream& os, const Tile&);
};


#endif //PHANTOMOPERAAI_TILE_HPP
