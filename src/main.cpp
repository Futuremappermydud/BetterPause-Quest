#include "main.hpp"
#include "modconfig.hpp"
#include "assets.hpp"
#include "ColorResolver.hpp"
#include "UI/SettingsViewController.hpp"
#include "ImageContentBehaviour.hpp"

#include "bsml/shared/BSMLDataCache.hpp"
#include "bsml/shared/BSML.hpp"

#include "UnityEngine/Vector2.hpp"
#include "UnityEngine/GameObject.hpp"
#include "UnityEngine/Transform.hpp"
#include "UnityEngine/RectTransform.hpp"
#include "UnityEngine/SceneManagement/SceneManager.hpp"
#include "HMUI/ImageView.hpp"
#include "HMUI/CurvedTextMeshPro.hpp"
#include "GlobalNamespace/LevelBar.hpp"
#include "GlobalNamespace/IPreviewBeatmapLevel.hpp"
#include "GlobalNamespace/BeatmapCharacteristicSO.hpp"
#include "GlobalNamespace/BeatmapDifficulty.hpp"
#include "scotland2/shared/loader.hpp"
#include <tuple>

modloader::ModInfo modInfo{MOD_ID, VERSION, GIT_COMMIT};

Logger& getLogger() {
    static Logger* logger = new Logger(modInfo);
    return *logger;
}

MAKE_HOOK_MATCH(SetDataHook, static_cast<void(GlobalNamespace::LevelBar::*)(GlobalNamespace::IPreviewBeatmapLevel*, GlobalNamespace::BeatmapCharacteristicSO*, GlobalNamespace::BeatmapDifficulty)>(&GlobalNamespace::LevelBar::Setup), void,
                              GlobalNamespace::LevelBar* self, 
                              GlobalNamespace::IPreviewBeatmapLevel* previewBeatmapLevel, GlobalNamespace::BeatmapCharacteristicSO* beatmapCharacteristic, GlobalNamespace::BeatmapDifficulty beatmapDifficulty) {
    SetDataHook(self, previewBeatmapLevel, beatmapCharacteristic, beatmapDifficulty);
    getLogger().info("Setting up...");
    
    auto scene = UnityEngine::SceneManagement::SceneManager::GetActiveScene();
    if(scene.get_name() != "GameCore") return;
    getLogger().info("in proper scene");
    auto transform = self->get_transform();
    getLogger().info("got transform");
    auto bg = transform->Find("BG")->GetComponent<HMUI::ImageView*>();
    auto cover = transform->Find("SongArtwork")->GetComponent<HMUI::ImageView*>();
    getLogger().info("got bg and cover");
    auto buttons = transform->get_parent()->Find("Buttons");
	auto menu = buttons->Find("BackButton")->get_gameObject();
	auto res = buttons->Find("RestartButton")->get_gameObject();
	auto con = buttons->Find("ContinueButton")->get_gameObject();
    getLogger().info("got buttons");
    bg->____skew = 0.18f;
    bg->set_overrideSprite(nullptr);
    bg->set_gradient(true);
    bg->set_color(UnityEngine::Color(1.0f, 1.0f, 1.0f, 0.97f));
    getLogger().info("setting bg anchor min");
    bg->get_rectTransform()->set_anchorMin(UnityEngine::Vector2(-0.04, 0.5f));
    getLogger().info("set bg props");

    cover->____skew = 0.18f;
    getLogger().info("set cover skew");
    auto rect = cover->get_rectTransform();
    rect->set_sizeDelta(UnityEngine::Vector2(13.5f, 13.5f));
	rect->set_anchorMin(UnityEngine::Vector2(0.01f, rect->get_anchorMin().y));
    getLogger().info("set cover rect props");

    auto menuContent = menu->AddComponent<BetterPause::ImageContentBehaviour*>();
	auto restartContent = res->AddComponent<BetterPause::ImageContentBehaviour*>();
	auto continueContent = con->AddComponent<BetterPause::ImageContentBehaviour*>();

    auto grad = BetterPause::ColorResolver::GetBackgroundGradient(true);
    bg->set_color0(std::get<0>(grad));
    bg->set_color1(std::get<1>(grad));
    bg->_gradientDirection = getModConfig().BackgroundGradientDirection.GetValue() == "Vertical" ? HMUI::ImageView::GradientDirection::Vertical : HMUI::ImageView::GradientDirection::Horizontal;
    getLogger().info("set bg color props");

    self->_songNameText->set_color(BetterPause::ColorResolver::GetSongNameColor());
    self->_authorNameText->set_color(BetterPause::ColorResolver::GetAuthorColor());
    self->_authorNameText->set_richText(true);
    self->_authorNameText->set_text(BetterPause::ColorResolver::GetAuthorString(previewBeatmapLevel->get_levelAuthorName(), previewBeatmapLevel->get_songAuthorName()));

    auto diffColor = BetterPause::ColorResolver::GetDiffColor();
    self->_difficultyText->set_color(diffColor);
    self->_characteristicIconImageView->set_color(diffColor);

    BetterPause::ColorResolver::UpdateMenuButton(menuContent);
	BetterPause::ColorResolver::UpdateRestartButton(restartContent);
	BetterPause::ColorResolver::UpdateContinueButton(continueContent);
}

extern "C" void setup(CModInfo* info) {
    info->id = modInfo.id.c_str();
    info->version = modInfo.version.c_str();
    info->version_long = modInfo.versionLong;
}

extern "C" void late_load() {
    il2cpp_functions::Init();

    INSTALL_HOOK(getLogger(), SetDataHook);

    custom_types::Register::AutoRegister();

    BSML::Register::RegisterMainMenu<BetterPause::SettingsViewController*>("Better Pause", "Better Pause", "");

    getModConfig().Init(modInfo);
}

BSML_DATACACHE(cover)
{
    return IncludedAssets::cover_png;
}

BSML_DATACACHE(dot)
{
    return IncludedAssets::dot_png;
}