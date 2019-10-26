//
// Created by waether on 21/10/19.
//

#ifndef C_NET_MESSAGEEVALUATOR_HPP
#define C_NET_MESSAGEEVALUATOR_HPP

#include <string>

class KeyEvaluator {
public:
    enum Type {
        Data,
        GameState,
        Question,
        Unknown,
        gStateBlocked,
        gStateCharacters,
        gStateExit,
        gStateFantom,
        gStateNumberTour,
        gStateCarlotta,
        gStateShadow,
        gStateTiles
    };

    static Type Evaluate(const std::string &);
};


#endif //C_NET_MESSAGEEVALUATOR_HPP
