//
// Created by waether on 28/10/19.
//

#ifndef PHANTOMOPERAAI_GAMEDATA_HPP
#define PHANTOMOPERAAI_GAMEDATA_HPP

#include <nlohmann/json.hpp>
#include "Character.hpp"

class GameData {
public:
    enum Mode {
        Char,
        Number
    };

private:
    std::vector<Character>  _characters;
    std::vector<int>        _numbers;
    Mode                    _mode;

public:

    void                    Update          (nlohmann::json &);
    Mode                    getMode         ();
    std::vector<Character>  getCharacters   ();
    std::vector<int>        getNumbers      ();

};


#endif //PHANTOMOPERAAI_GAMEDATA_HPP
