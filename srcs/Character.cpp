//
// Created by waether on 26/10/19.
//

#include "Character.hpp"

const Color::Colors &Character::getColor() {
    return _color;
}

const int &Character::getPosition() {
    return _position;
}

const bool &Character::getPower() {
    return _power;
}

const bool &Character::isSuspect() {
    return _suspect;
}

void Character::setColor(const Color::Colors& color) {
    _color = color;
}

void Character::setPosition(const int& position) {
    _position = position;
}

void Character::setPower(const bool& power) {
    _power = power;
}

void Character::setSuspect(const bool& suspect) {
    _suspect = suspect;
}

void Character::setCharacter(const Color::Colors& color,
                            const int& position,
                            const bool& power,
                            const bool& suspect) {
    setColor(color);
    setPosition(position);
    setPower(power);
    setSuspect(suspect);
}

Character::Character(nlohmann::json jsoncharacter) {
    unsigned int set = 0;

    for (nlohmann::json::iterator it = jsoncharacter.begin(); it != jsoncharacter.end(); ++it) {
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
            Logger::Error() << "Unknown key inside Character." << std::endl;
        }
    }

    if (set != 4) {
        Logger::Error() << "Character badly initialized." << std::endl;
    }
}

std::ostream &operator<<(std::ostream &os, const Character &car) {
    os << "Character : {color: ";

    switch (car._color) {
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

    os << ", position: " << car._position
       << ", is_suspect: "
       << static_cast<bool>(car._suspect == 1)
       << ", has_power: "
       << static_cast<bool>(car._power == 1)
       << "}";

    return os;
}
