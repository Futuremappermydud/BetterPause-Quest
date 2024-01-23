#include "ColorResolver.hpp"
#include "main.hpp"
#include "System/String.hpp"
#include <iomanip>
//hi

std::tuple<UnityEngine::Color, UnityEngine::Color> BetterPause::ColorResolver::GetBackgroundGradient(bool inGame)
{
    auto color0 = getModConfig().EnableBackgroundGradient.GetValue() ? HexToColor(getModConfig().BackgroundGradientColor2.GetValue()) : UnityEngine::Color(0.68f, 0.57f, 0.0f, 1.0f);
	auto color1 = getModConfig().EnableBackgroundGradient.GetValue() ? HexToColor(getModConfig().BackgroundGradientColor1.GetValue()) : UnityEngine::Color(0.68f, 0.57f, 0.0f, 0.94f);
	return inGame ? std::make_tuple(color1, color0) : std::make_tuple(color0, color1);
}

UnityEngine::Color BetterPause::ColorResolver::GetDiffColor()
{
    return getModConfig().EnableDiffColor.GetValue() ? HexToColor(getModConfig().DiffColor.GetValue()) : UnityEngine::Color(1.0f, 1.0f, 1.0f, 0.75f);
}

UnityEngine::Color BetterPause::ColorResolver::GetAuthorColor()
{
    return getModConfig().EnableAuthorNameColor.GetValue() ? HexToColor(getModConfig().AuthorNameColor.GetValue()) : UnityEngine::Color(1.0f, 1.0f, 1.0f, 0.75f);
}

UnityEngine::Color BetterPause::ColorResolver::GetSongNameColor()
{
    return getModConfig().EnableSongNameColor.GetValue() ? HexToColor(getModConfig().SongNameColor.GetValue()) : UnityEngine::Color::get_white();
}

StringW BetterPause::ColorResolver::GetAuthorString(StringW mapper, StringW author)
{
    if (!System::String::IsNullOrWhiteSpace(mapper) && getModConfig().EnableMapperName.GetValue())
	{
        std::string val = getModConfig().MapperNameColor.GetValue();
        if (val[0] == '#')
            val.erase(0, 1);
		std::string mapperHex = getModConfig().EnableMapperNameColor.GetValue() ? val : "ff69b4";
		return u"<size=80%>" + author + u"</size> <size=90%>[<color=#" + mapperHex + u">" + mapper + u"</color>]</size>";
	}
	else 
	{
		return author;
	}
}

void UpdateButton(BetterPause::ImageContentBehaviour* content, UnityEngine::Color def, UnityEngine::Color hov)
{
	content->defaultColor = def;
	content->hoverColor = hov;
}

void BetterPause::ColorResolver::UpdateMenuButton(BetterPause::ImageContentBehaviour* content)
{
	UpdateButton(content, HexToColor(getModConfig().CustomButtonColorMenuDefault.GetValue()), HexToColor(getModConfig().CustomButtonColorMenuHover.GetValue()));
}

void BetterPause::ColorResolver::UpdateRestartButton(BetterPause::ImageContentBehaviour* content)
{
	UpdateButton(content, HexToColor(getModConfig().CustomButtonColorRestartDefault.GetValue()), HexToColor(getModConfig().CustomButtonColorRestartHover.GetValue()));
}

void BetterPause::ColorResolver::UpdateContinueButton(BetterPause::ImageContentBehaviour* content)
{
	UpdateButton(content, HexToColor(getModConfig().CustomButtonColorContinueDefault.GetValue()), HexToColor(getModConfig().CustomButtonColorContinueHover.GetValue()));
}