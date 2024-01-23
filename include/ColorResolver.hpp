#pragma once
#include "modconfig.hpp"
#include "colorfuncs.hpp"
#include "ImageContentBehaviour.hpp"
#include <tuple>

namespace BetterPause
{
    class ColorResolver
    {
    public:
        static std::tuple<UnityEngine::Color, UnityEngine::Color> GetBackgroundGradient(bool inGame);
        //TODO: IForgor implementation
        //static std::tuple<UnityEngine::Color, UnityEngine::Color> GetIForgorGradient();
        static UnityEngine::Color GetDiffColor();
        static UnityEngine::Color GetAuthorColor();
        static UnityEngine::Color GetSongNameColor();
        static StringW GetAuthorString(StringW mapper, StringW author);
        static void UpdateMenuButton(BetterPause::ImageContentBehaviour* content);
        static void UpdateRestartButton(BetterPause::ImageContentBehaviour* content);
        static void UpdateContinueButton(BetterPause::ImageContentBehaviour* content);
    };
}