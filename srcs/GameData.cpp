//
// Created by waether on 28/10/19.
//

#include <Logger.hpp>
#include "GameData.hpp"

void GameData::Update(nlohmann::json & rawData) {
    Logger::Log() << "Updating GameData ..." << std::endl;

    _characters.clear();
    _numbers.clear();

    for (const nlohmann::json &elem : rawData) {

        if (elem.is_object()) {
            _mode = GameData::Char;

            Character tmp(elem);
            Logger::Log() << "\t  " << tmp << std::endl;
            _characters.emplace_back(tmp);
        } else if (elem.is_number()) {
            _mode = GameData::Number;

            _numbers.emplace_back(elem);
            Logger::Log() << "\tNumber : " << static_cast<int>(elem) << std::endl;
        }

    }

    Logger::Log() << "GameData Updated." << std::endl;
}

GameData::Mode GameData::getMode() {
    return _mode;
}

std::vector<Character> GameData::getCharacters() {
    return _characters;
}

std::vector<int> GameData::getNumbers() {
    return _numbers;
}
