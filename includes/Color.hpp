//
// Created by waether on 26/10/19.
//

#ifndef PHANTOMOPERAAI_COLOR_HPP
#define PHANTOMOPERAAI_COLOR_HPP

#include <string>

class Color {
public:
    enum Colors {
        Blue,
        Grey,
        Black,
        Red,
        Purple,
        Brown,
        Pink,
        White,
        Unknown
    };

    static Colors Evaluate(const std::string &);

};


#endif //PHANTOMOPERAAI_COLOR_HPP
