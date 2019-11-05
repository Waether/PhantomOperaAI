//
// Created by waether on 26/10/19.
//

#include "Tile.hpp"

const Color::Colors &Tile::getColor() {
    return _color;
}

const int &Tile::getPosition() {
    return _position;
}

const bool &Tile::getPower() {
    return _power;
}

const bool &Tile::isSuspect() {
    return _suspect;
}

void Tile::setColor(const Color::Colors& color) {
    _color = color;
}

void Tile::setPosition(const int& position) {
    _position = position;
}

void Tile::setPower(const bool& power) {
    _power = power;
}

void Tile::setSuspect(const bool& suspect) {
    _suspect = suspect;
}

void Tile::setTiles(const Color::Colors& color,
                            const int& position,
                            const bool& power,
                            const bool& suspect) {
    setColor(color);
    setPosition(position);
    setPower(power);
    setSuspect(suspect);
}

Tile::Tile(nlohmann::json jsontiles) {
    unsigned int set = 0;

    for (nlohmann::json::iterator it = jsontiles.begin(); it != jsontiles.end(); ++it) {
        if (it.key() == "color") {
            _color = Color::Evaluate(it.value());
            set++;
        } else if (it.key() == "position") {
            _position = it.value();
            set++;
        } else if (it.key() == "power") {
            _power = it.value();
            set++;
        } else if (it.key() == "suspect") {
            _suspect = it.value();
            set++;
        } else {
            Logger::Error() << "Unknown key inside Tile." << std::endl;
        }
    }

    if (set != 4) {
        Logger::Error() << "Tile badly initialized." << std::endl;
    }
}

std::ostream &operator<<(std::ostream &os, const Tile &tile) {
    os << "Tile : {color: ";

    switch (tile._color) {
        case Color::Blue :
            os << "\"blue\"";
            break;
        case Color::Grey :
            os << "\"grey\"";
            break;
        case Color::Black :
            os << "\"black\"";
            break;
        case Color::Red :
            os << "\"red\"";
            break;
        case Color::Purple :
            os << "\"purple\"";
            break;
        case Color::Brown :
            os << "\"brown\"";
            break;
        case Color::Pink :
            os << "\"pink\"";
            break;
        case Color::White :
            os << "\"white\"";
            break;
        default:
            os << "\"unknown\"";
            break;
    }

    os << std::boolalpha;

    os << ", position: " << tile._position
       << ", is_suspect: "
       << static_cast<bool>(tile._suspect == 1)
       << ", has_power: "
       << static_cast<bool>(tile._power == 1)
       << "}";

    return os;
}
