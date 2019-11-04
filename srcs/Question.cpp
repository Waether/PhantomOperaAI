//
// Created by waether on 26/10/19.
//

#include "Question.hpp"

Question::Questions Question::Evaluate(const std::string &qst) {

    std::regex regexCharacterSelection("^select character/?$",
                                       std::regex_constants::ECMAScript | std::regex_constants::icase);

    if (std::regex_search(qst, regexCharacterSelection)) {
        Logger::Log() << "\tCharacterSelection" << std::endl;
        return Question::CharacterSelection;
    }


    std::regex regexPositionSelection("^select position/?$",
                                       std::regex_constants::ECMAScript | std::regex_constants::icase);

    if (std::regex_search(qst, regexPositionSelection)) {
        Logger::Log() << "\tPositionSelection" << std::endl;
        return Question::PositionSelection;
    }


    std::regex regexActivatePower("^activate [a-z]{3,6} power/?$",
                                      std::regex_constants::ECMAScript | std::regex_constants::icase);

    if (std::regex_search(qst, regexActivatePower)) {
        Logger::Log() << "\tActivatePower" << std::endl;
        return Question::ActivatePower;
    }


    std::regex regexHandlePower("^[a-z]{3,6} character power/?$",
                                  std::regex_constants::ECMAScript | std::regex_constants::icase);

    if (std::regex_search(qst, regexHandlePower)) {
        Logger::Log() << "\tHandlePower" << std::endl;
        return Question::HandlePower;
    }


    std::regex regexPowerExit("^[a-z]{3,6} character power exit/?$",
                                std::regex_constants::ECMAScript | std::regex_constants::icase);

    if (std::regex_search(qst, regexPowerExit)) {
        Logger::Log() << "\tPowerExit" << std::endl;
        return Question::PowerExit;
    }


    std::regex regexPowerRoom("^[a-z]{3,6} character power room/?$",
                              std::regex_constants::ECMAScript | std::regex_constants::icase);

    if (std::regex_search(qst, regexPowerRoom)) {
        Logger::Log() << "\tPowerRoom" << std::endl;
        return Question::PowerRoom;
    }


    std::regex regexPowerMove("^[a-z]{3,6} character power move/?$",
                              std::regex_constants::ECMAScript | std::regex_constants::icase);

    if (std::regex_search(qst, regexPowerMove)) {
        Logger::Log() << "\tPowerMove" << std::endl;
        return Question::PowerMove;
    }


    std::regex regexPowerMoveTarget("^[a-z]{3,6} character power move [a-z]{3,6}/?$",
                              std::regex_constants::ECMAScript | std::regex_constants::icase);

    if (std::regex_search(qst, regexPowerMoveTarget)) {
        Logger::Log() << "\tPowerMoveTarget" << std::endl;
        return Question::PowerMoveTarget;
    }

    Logger::Error() << "Unknown Question : " << qst << std::endl;

    return Question::Unknown;
}
