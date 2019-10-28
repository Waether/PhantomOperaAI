//
// Created by waether on 28/10/19.
//

#include <Logger.hpp>
#include "GameData.hpp"

void GameData::Update(nlohmann::json & rawData) {
    Logger::Log() << "Updating GameData ..." << std::endl;

    for (const nlohmann::json &elem : rawData) {

        Character tmp(elem);
        Logger::Log() << "\t  " << tmp << std::endl;
        _data.emplace_back(tmp);
    }

    Logger::Log() << "GameData Updated." << std::endl;
}
