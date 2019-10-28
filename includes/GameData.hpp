//
// Created by waether on 28/10/19.
//

#ifndef PHANTOMOPERAAI_GAMEDATA_HPP
#define PHANTOMOPERAAI_GAMEDATA_HPP


#include <nlohmann/json.hpp>
#include "Character.hpp"

class GameData {
private:
    std::vector<Character> _data;

public:
    void Update(nlohmann::json &);

};


#endif //PHANTOMOPERAAI_GAMEDATA_HPP
