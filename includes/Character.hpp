//
// Created by waether on 26/10/19.
//

#ifndef PHANTOMOPERAAI_CHARACTER_HPP
#define PHANTOMOPERAAI_CHARACTER_HPP

#include "Color.hpp"
#include "nlohmann/json.hpp"
#include "Logger.hpp"

class Character {
public:
    Color::Colors _color;
    int _position;
    bool _power;
    bool _suspect;

public:
    explicit Character(nlohmann::json);

    const Color::Colors & getColor();
    const int & getPosition();
    const bool & getPower();
    const bool & isSuspect();

    friend std::ostream & operator<<(std::ostream& os, const Character&);
};


#endif //PHANTOMOPERAAI_CHARACTER_HPP
