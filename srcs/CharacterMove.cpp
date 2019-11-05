//
// Created by waether on 05/11/19.
//

#include "CharacterMove.hpp"

const std::vector<Move> &CharacterMove::getMoveForCharacter(const Character &character, const GameState &gState) {

    std::vector<Move> allmoves;
    std::vector<Move> tmp;

    tmp = CharacterMove::getBaseMove(character, gState);

    allmoves.insert(allmoves.end(), tmp.begin(), tmp.end());

    switch (character._color) {
        case Color::Blue:
            tmp = CharacterMove::getMoveForBlue(gState);
            break;
        case Color::Grey:
            tmp = CharacterMove::getMoveForGrey(gState);
            break;
        case Color::Black:
            tmp = CharacterMove::getMoveForBlack(gState);
            break;
        case Color::Red:
            tmp = CharacterMove::getMoveForRed(gState);
            break;
        case Color::Purple:
            tmp = CharacterMove::getMoveForPurple(gState);
            break;
        case Color::Brown:
            tmp = CharacterMove::getMoveForBrown(gState);
            break;
        case Color::Pink:
            tmp = CharacterMove::getMoveForPink(gState);
            break;
        case Color::White:
            tmp = CharacterMove::getMoveForWhite(gState);
            break;
        case Color::Unknown:
            tmp.clear();
            break;
    }

    allmoves.insert(allmoves.end(), tmp.begin(), tmp.end());

    return allmoves;
}

const std::vector<Move> &CharacterMove::getMoveForBlue(const GameState &gState) {
    return <#initializer#>;
}

const std::vector<Move> &CharacterMove::getMoveForGrey(const GameState &gState) {
    return <#initializer#>;
}

const std::vector<Move> &CharacterMove::getMoveForBlack(const GameState &gState) {
    return <#initializer#>;
}

const std::vector<Move> &CharacterMove::getMoveForRed(const GameState &gState) {
    return <#initializer#>;
}

const std::vector<Move> &CharacterMove::getMoveForPurple(const GameState &gState) {
    return <#initializer#>;
}

const std::vector<Move> &CharacterMove::getMoveForBrown(const GameState &gState) {
    return <#initializer#>;
}

const std::vector<Move> &CharacterMove::getMoveForPink(const GameState &gState) {
    return <#initializer#>;
}

const std::vector<Move> &CharacterMove::getMoveForWhite(const GameState &gState) {
    return <#initializer#>;
}

const std::vector<Move> &CharacterMove::getBaseMove(const Character &character, const GameState &gState) {
    return <#initializer#>;
}
