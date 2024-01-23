#pragma once

#include "config-utils/shared/config-utils.hpp"
#include "UnityEngine/Color.hpp"

DECLARE_CONFIG(ModConfig,
    // General
    CONFIG_VALUE(Enabled, bool, "Enabled", true);
    CONFIG_VALUE(EnableMapperName, bool, "EnableMapperName", true);

    //Background
    CONFIG_VALUE(EnableBackgroundGradient, bool, "EnableBackgroundGradient", false);
    CONFIG_VALUE(BackgroundGradientColor1, std::string, "BackgroundGradientColor1", "#ffeb04");
    CONFIG_VALUE(BackgroundGradientColor2, std::string, "BackgroundGradientColor2", "#ffeb04");
    CONFIG_VALUE(BackgroundGradientDirection, std::string, "BackgroundGradientDirection", "Horizontal");

    //Text
    CONFIG_VALUE(EnableSongNameColor, bool, "EnableSongNameColor", false);
    CONFIG_VALUE(SongNameColor, std::string, "SongNameColor", "#808080");

    CONFIG_VALUE(EnableAuthorNameColor, bool, "EnableAuthorNameColor", false);
    CONFIG_VALUE(AuthorNameColor, std::string, "AuthorNameColor", "#808080");

    CONFIG_VALUE(EnableMapperNameColor, bool, "EnableMapperNameColor", false);
    CONFIG_VALUE(MapperNameColor, std::string, "MapperNameColor", "#ff66b3");

    CONFIG_VALUE(EnableDiffColor, bool, "EnableDiffColor", false);
    CONFIG_VALUE(DiffColor, std::string, "DiffColor", "#bfbfbf");

    //Custom Button Colors
    CONFIG_VALUE(EnableCustomButtonColors, bool, "EnableCustomButtonColors", false);
	CONFIG_VALUE(CustomButtonColorMenuDefault, std::string, "CustomButtonColorMenuDefault", "#202020");
	CONFIG_VALUE(CustomButtonColorMenuHover, std::string, "CustomButtonColorMenuHover", "#ff24e6");
	CONFIG_VALUE(CustomButtonColorRestartDefault, std::string, "CustomButtonColorRestartDefault", "#202020");
	CONFIG_VALUE(CustomButtonColorRestartHover, std::string, "CustomButtonColorRestartHover", "#ff24e6");
	CONFIG_VALUE(CustomButtonColorContinueDefault, std::string, "CustomButtonColorContinueDefault", "#202020");
	CONFIG_VALUE(CustomButtonColorContinueHover, std::string, "CustomButtonColorContinueHover", "#ff24e6");
);