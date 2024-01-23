#include "UI/SettingsViewController.hpp"
#include "assets.hpp"
#include "modconfig.hpp"
#include "ColorResolver.hpp"
#include <tuple>

#include "bsml/shared/BSML.hpp"
#include "bsml/shared/BSML/Components/Backgroundable.hpp"

DEFINE_TYPE(BetterPause, SettingsViewController);

void BetterPause::SettingsViewController::RefreshUI() {
    if (pauseWrapper == nullptr) return;

    auto wrapperImage = pauseWrapper->GetComponent<HMUI::ImageView*>();
	auto grad = BetterPause::ColorResolver::GetBackgroundGradient(true);
    wrapperImage->set_color0(std::get<0>(grad));
    wrapperImage->set_color1(std::get<1>(grad));
	wrapperImage->_gradientDirection = getModConfig().BackgroundGradientDirection.GetValue() == "Vertical" ? HMUI::ImageView::GradientDirection::Vertical : HMUI::ImageView::GradientDirection::Horizontal;

	nameTxt->set_color(BetterPause::ColorResolver::GetSongNameColor());
	authorTxt->set_color(BetterPause::ColorResolver::GetAuthorColor());
	authorTxt->set_text(BetterPause::ColorResolver::GetAuthorString("Mapper", "Song Author"));

    auto diffColor = BetterPause::ColorResolver::GetDiffColor();
    diffTxt->set_color(diffColor);
    diffImg->set_color(diffColor);

    BetterPause::ColorResolver::UpdateMenuButton(menuContent);
    BetterPause::ColorResolver::UpdateRestartButton(restartContent);
    BetterPause::ColorResolver::UpdateContinueButton(continueContent);
}

template <class Out, class T, class Predicate>
    inline ArrayW<Out> Select(ArrayW<T> array, Predicate pred)
{
    ArrayW<Out> newArray(array.Length());
    for (int i = 0; i < array.Length(); i++) {
        newArray[i] = pred(array[i]);
    }
    return newArray;
}

UnityEngine::Material* GetMat(std::string str)
{
    return UnityEngine::Resources::FindObjectsOfTypeAll<UnityEngine::Material*>().First([str](UnityEngine::Material* x) {
                                                                                             return x->get_name() == str;
                                                                                         });
}

UnityEngine::Sprite* GetBGSprite(std::string str)
{
    return UnityEngine::Resources::FindObjectsOfTypeAll<UnityEngine::Sprite*>().First([str](UnityEngine::Sprite* x) {
                                                                                         return x->get_name() == str;
                                                                                     });
}

void BetterPause::SettingsViewController::DidActivate(bool firstActivation, bool addedToHierarchy, bool screenSystemEnabling) {

    if(firstActivation) {
        BSML::parse_and_construct(IncludedAssets::settings_bsml, this->get_transform(), this);

        auto getBgSprite = GetBGSprite("RoundRect10BorderFade");

        for(auto x : Select<HMUI::ImageView*>(GetComponentsInChildren<BSML::Backgroundable*>(true), [](BSML::Backgroundable* x) {return x->GetComponent<HMUI::ImageView*>();})) {
            if(!x || UnityEngine::Color::op_Inequality(x->get_color0(), UnityEngine::Color::get_white()) || x->get_sprite()->get_name() != "RoundRect10" || x->get_transform()->get_parent()->get_name() != "BSMLTab")
                continue;
            x->____skew = 0.0f;
            x->set_overrideSprite(nullptr);
            x->set_sprite(getBgSprite);
            x->set_color(UnityEngine::Color(1.0f, 1.0f, 1.0f, 0.4f));
        }   

        auto wrapperImage = pauseWrapper->GetComponent<HMUI::ImageView*>();
		wrapperImage->____skew = 0.18f;
		wrapperImage->set_overrideSprite(nullptr);
		wrapperImage->set_gradient(true);
		wrapperImage->set_color(UnityEngine::Color(1.0f, 1.0f, 1.0f, 0.85f));

		pauseImg->____skew = 0.18f;
		pauseImg->set_material(GetMat("UINoGlowRoundEdge"));

        menuContent = menuBtn->get_gameObject()->AddComponent<BetterPause::ImageContentBehaviour*>();
	    restartContent = restartBtn->get_gameObject()->AddComponent<BetterPause::ImageContentBehaviour*>();
	    continueContent = continueBtn->get_gameObject()->AddComponent<BetterPause::ImageContentBehaviour*>();
    }
    RefreshUI();
}

//General

bool BetterPause::SettingsViewController::get_Enabled() { return getModConfig().Enabled.GetValue(); }
void BetterPause::SettingsViewController::set_Enabled(bool value)
{
    getModConfig().Enabled.SetValue(value);
    RefreshUI();
}

bool BetterPause::SettingsViewController::get_MapperName() { return getModConfig().EnableMapperName.GetValue(); }
void BetterPause::SettingsViewController::set_MapperName(bool value)
{
    getModConfig().EnableMapperName.SetValue(value);
    RefreshUI();
}

//Background 

bool BetterPause::SettingsViewController::get_BgGradient() { return getModConfig().EnableBackgroundGradient.GetValue(); }
void BetterPause::SettingsViewController::set_BgGradient(bool value)
{
    getModConfig().EnableBackgroundGradient.SetValue(value);
    RefreshUI();
}

UnityEngine::Color BetterPause::SettingsViewController::get_BgGradient1() { return HexToColor(getModConfig().BackgroundGradientColor1.GetValue()); }
void BetterPause::SettingsViewController::set_BgGradient1(UnityEngine::Color value)
{
    getModConfig().BackgroundGradientColor1.SetValue(ColorToHex(value));
    RefreshUI();
}

UnityEngine::Color BetterPause::SettingsViewController::get_BgGradient2() { return HexToColor(getModConfig().BackgroundGradientColor2.GetValue()); }
void BetterPause::SettingsViewController::set_BgGradient2(UnityEngine::Color value)
{
    getModConfig().BackgroundGradientColor2.SetValue(ColorToHex(value));
    RefreshUI();
}

StringW BetterPause::SettingsViewController::get_BackgroundDirection() { return getModConfig().BackgroundGradientDirection.GetValue(); }
void BetterPause::SettingsViewController::set_BackgroundDirection(StringW value)
{
    getModConfig().BackgroundGradientDirection.SetValue(value);
    RefreshUI();
}

//Texts

bool BetterPause::SettingsViewController::get_SongName() { return getModConfig().EnableSongNameColor.GetValue(); }
void BetterPause::SettingsViewController::set_SongName(bool value)
{
    getModConfig().EnableSongNameColor.SetValue(value);
    RefreshUI();
}

UnityEngine::Color BetterPause::SettingsViewController::get_SongNameColor() { return HexToColor(getModConfig().SongNameColor.GetValue()); }
void BetterPause::SettingsViewController::set_SongNameColor(UnityEngine::Color value)
{
    getModConfig().SongNameColor.SetValue(ColorToHex(value));
    RefreshUI();
}

bool BetterPause::SettingsViewController::get_AuthorName() { return getModConfig().EnableAuthorNameColor.GetValue(); }
void BetterPause::SettingsViewController::set_AuthorName(bool value)
{
    getModConfig().EnableAuthorNameColor.SetValue(value);
    RefreshUI();
}

UnityEngine::Color BetterPause::SettingsViewController::get_AuthorNameColor() { return HexToColor(getModConfig().AuthorNameColor.GetValue()); }
void BetterPause::SettingsViewController::set_AuthorNameColor(UnityEngine::Color value)
{
    getModConfig().AuthorNameColor.SetValue(ColorToHex(value));
    RefreshUI();
}

bool BetterPause::SettingsViewController::get_CustomMapperName() { return getModConfig().EnableMapperNameColor.GetValue(); }
void BetterPause::SettingsViewController::set_CustomMapperName(bool value)
{
    getModConfig().EnableMapperNameColor.SetValue(value);
    RefreshUI();
}

UnityEngine::Color BetterPause::SettingsViewController::get_MapperNameColor() { return HexToColor(getModConfig().MapperNameColor.GetValue()); }
void BetterPause::SettingsViewController::set_MapperNameColor(UnityEngine::Color value)
{
    getModConfig().MapperNameColor.SetValue(ColorToHex(value));
    RefreshUI();
}

bool BetterPause::SettingsViewController::get_CustomDiffColor() { return getModConfig().EnableDiffColor.GetValue(); }
void BetterPause::SettingsViewController::set_CustomDiffColor(bool value)
{
    getModConfig().EnableDiffColor.SetValue(value);
    RefreshUI();
}

UnityEngine::Color BetterPause::SettingsViewController::get_DiffColor() { return HexToColor(getModConfig().DiffColor.GetValue()); }
void BetterPause::SettingsViewController::set_DiffColor(UnityEngine::Color value)
{
    getModConfig().DiffColor.SetValue(ColorToHex(value));
    RefreshUI();
}

//Buttons

bool BetterPause::SettingsViewController::get_ButtonColors() { return getModConfig().EnableCustomButtonColors.GetValue(); }
void BetterPause::SettingsViewController::set_ButtonColors(bool value)
{
    getModConfig().EnableCustomButtonColors.SetValue(value);
    RefreshUI();
}

UnityEngine::Color BetterPause::SettingsViewController::get_MenuDefault() { return HexToColor(getModConfig().CustomButtonColorMenuDefault.GetValue()); }
void BetterPause::SettingsViewController::set_MenuDefault(UnityEngine::Color value)
{
    getModConfig().CustomButtonColorMenuDefault.SetValue(ColorToHex(value));
    RefreshUI();
}

UnityEngine::Color BetterPause::SettingsViewController::get_MenuHover() { return HexToColor(getModConfig().CustomButtonColorMenuHover.GetValue()); }
void BetterPause::SettingsViewController::set_MenuHover(UnityEngine::Color value)
{
    getModConfig().CustomButtonColorMenuHover.SetValue(ColorToHex(value));
    RefreshUI();
}

UnityEngine::Color BetterPause::SettingsViewController::get_RestartDefault() { return HexToColor(getModConfig().CustomButtonColorRestartDefault.GetValue()); }
void BetterPause::SettingsViewController::set_RestartDefault(UnityEngine::Color value)
{
    getModConfig().CustomButtonColorRestartDefault.SetValue(ColorToHex(value));
    RefreshUI();
}

UnityEngine::Color BetterPause::SettingsViewController::get_RestartHover() { return HexToColor(getModConfig().CustomButtonColorRestartHover.GetValue()); }
void BetterPause::SettingsViewController::set_RestartHover(UnityEngine::Color value)
{
    getModConfig().CustomButtonColorRestartHover.SetValue(ColorToHex(value));
    RefreshUI();
}

UnityEngine::Color BetterPause::SettingsViewController::get_ContinueDefault() { return HexToColor(getModConfig().CustomButtonColorContinueDefault.GetValue()); }
void BetterPause::SettingsViewController::set_ContinueDefault(UnityEngine::Color value)
{
    getModConfig().CustomButtonColorContinueDefault.SetValue(ColorToHex(value));
    RefreshUI();
}

UnityEngine::Color BetterPause::SettingsViewController::get_ContinueHover() { return HexToColor(getModConfig().CustomButtonColorContinueHover.GetValue()); }
void BetterPause::SettingsViewController::set_ContinueHover(UnityEngine::Color value)
{
    getModConfig().CustomButtonColorContinueHover.SetValue(ColorToHex(value));
    RefreshUI();
}