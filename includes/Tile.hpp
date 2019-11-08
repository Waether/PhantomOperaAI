//
// Created by waether on 26/10/19.
//

#ifndef PHANTOMOPERAAI_TILE_HPP
#define PHANTOMOPERAAI_TILE_HPP

#include "nlohmann/json.hpp"

#include "Character.hpp"
#include "Color.hpp"
#include "Logger.hpp"

class Tile {
public:
    Color::Colors   _color;
    int             _position;
    bool            _power;
    bool            _suspect;

public:
    explicit Tile(nlohmann::json);

    const Color::Colors &   getColor    ();
    const int &             getPosition ();
    const bool &            getPower    ();
    const bool &            isSuspect   ();

    void                    setColor    (const Color::Colors&);
    void                    setPosition (const int&);
    void                    setPower    (const bool&);
    void                    setSuspect  (const bool&);
    void                    setTiles    (const Color::Colors&, const int&, const bool&, const bool&);

    friend std::ostream & operator<<(std::ostream& os, const Tile&);
};

#endif //PHANTOMOPERAAI_TILE_HPP
