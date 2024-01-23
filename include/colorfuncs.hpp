#pragma once
#include <iomanip>
#include <sstream>
#include "UnityEngine/Color.hpp"

inline std::string ColorToHex(UnityEngine::Color color)
{
    std::stringstream ss;

    ss << "#";
    ss << std::hex << std::setw(2);
    ss << (int)(color.r * 255.0f) << (int)(color.g * 255.0f) << (int)(color.b * 255.0f);
    return ss.str();
}

inline UnityEngine::Color HexToColor(std::string input) {

    if (input[0] == '#')
        input.erase(0, 1);

    unsigned long value = stoul(input, nullptr, 16);

    UnityEngine::Color color;

    color.a = 1.0f;
    color.r = ((value >> 16) & 0xff) / 255.0f;
    color.g = ((value >> 8) & 0xff) / 255.0f;
    color.b = ((value >> 0) & 0xff) / 255.0f;
    return color;
}