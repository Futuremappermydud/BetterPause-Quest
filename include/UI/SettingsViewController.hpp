#include "HMUI/ViewController.hpp"
#include "HMUI/ImageView.hpp"
#include "HMUI/NoTransitionsButton.hpp"
#include "TMPro/TMP_Text.hpp"
#include "UnityEngine/Color.hpp"
#include "UnityEngine/Resources.hpp"
#include "UnityEngine/GameObject.hpp"

#include "colorfuncs.hpp"
#include "ImageContentBehaviour.hpp"

#include "custom-types/shared/macros.hpp"
#include "bsml/shared/macros.hpp"

DECLARE_CLASS_CODEGEN(BetterPause, SettingsViewController, HMUI::ViewController,
    void RefreshUI();

    DECLARE_DEFAULT_CTOR();

    DECLARE_OVERRIDE_METHOD(void, DidActivate, il2cpp_utils::il2cpp_type_check::MetadataGetter<&HMUI::ViewController::DidActivate>::methodInfo(), bool firstActivation, bool addedToHierarchy, bool screenSystemEnabling);

    DECLARE_INSTANCE_FIELD(UnityEngine::GameObject*, pauseWrapper);
    DECLARE_INSTANCE_FIELD(HMUI::ImageView*, pauseImg);
    DECLARE_INSTANCE_FIELD(TMPro::TMP_Text*, nameTxt);
    DECLARE_INSTANCE_FIELD(TMPro::TMP_Text*, authorTxt);
    DECLARE_INSTANCE_FIELD(TMPro::TMP_Text*, diffTxt);
    DECLARE_INSTANCE_FIELD(HMUI::ImageView*, diffImg);

    DECLARE_INSTANCE_FIELD(HMUI::NoTransitionsButton*, menuBtn);
    DECLARE_INSTANCE_FIELD(HMUI::NoTransitionsButton*, restartBtn);
    DECLARE_INSTANCE_FIELD(HMUI::NoTransitionsButton*, continueBtn);

    DECLARE_INSTANCE_FIELD(BetterPause::ImageContentBehaviour*, menuContent);
    DECLARE_INSTANCE_FIELD(BetterPause::ImageContentBehaviour*, restartContent);
    DECLARE_INSTANCE_FIELD(BetterPause::ImageContentBehaviour*, continueContent);

    DECLARE_BSML_PROPERTY(bool, Enabled);
    DECLARE_BSML_PROPERTY(bool, MapperName);

    DECLARE_BSML_PROPERTY(bool, BgGradient);
    DECLARE_BSML_PROPERTY(UnityEngine::Color, BgGradient1);
    DECLARE_BSML_PROPERTY(UnityEngine::Color, BgGradient2);
    DECLARE_BSML_PROPERTY(StringW, BackgroundDirection);

    DECLARE_BSML_PROPERTY(bool, SongName);
    DECLARE_BSML_PROPERTY(UnityEngine::Color, SongNameColor);

    DECLARE_BSML_PROPERTY(bool, AuthorName);
    DECLARE_BSML_PROPERTY(UnityEngine::Color, AuthorNameColor);

    DECLARE_BSML_PROPERTY(bool, CustomMapperName);
    DECLARE_BSML_PROPERTY(UnityEngine::Color, MapperNameColor);

    DECLARE_BSML_PROPERTY(bool, CustomDiffColor);
    DECLARE_BSML_PROPERTY(UnityEngine::Color, DiffColor);

    DECLARE_BSML_PROPERTY(bool, ButtonColors);
    DECLARE_BSML_PROPERTY(UnityEngine::Color, MenuDefault);
    DECLARE_BSML_PROPERTY(UnityEngine::Color, MenuHover);

    DECLARE_BSML_PROPERTY(UnityEngine::Color, RestartDefault);
    DECLARE_BSML_PROPERTY(UnityEngine::Color, RestartHover);

    DECLARE_BSML_PROPERTY(UnityEngine::Color, ContinueDefault);
    DECLARE_BSML_PROPERTY(UnityEngine::Color, ContinueHover);

    BSML_OPTIONS_LIST_OBJECT(directionOptions, "Horizontal", "Vertical");
)