//
// Created by waether on 26/10/19.
//

#include "Color.hpp"

Color::Colors Color::Evaluate(const std::string & colortxt) {

    if (colortxt == "blue")
        return Color::Blue;
    if (colortxt == "grey")
        return Color::Grey;
    if (colortxt == "black")
        return Color::Black;
    if (colortxt == "red")
        return Color::Red;
    if (colortxt == "purple")
        return Color::Purple;
    if (colortxt == "brown")
        return Color::Brown;
    if (colortxt == "pink")
        return Color::Pink;
    if (colortxt == "white")
        return Color::White;
    return Color::Unknown;
}
