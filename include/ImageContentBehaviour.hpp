#pragma once

#include "custom-types/shared/macros.hpp"
#include "UnityEngine/MonoBehaviour.hpp"
#include "UnityEngine/Color.hpp"
#include "UnityEngine/Transform.hpp"
#include "UnityEngine/GameObject.hpp"
#include "HMUI/ImageView.hpp"
#include "HMUI/NoTransitionsButton.hpp"

DECLARE_CLASS_CODEGEN(BetterPause, ImageContentBehaviour, UnityEngine::MonoBehaviour,
    DECLARE_INSTANCE_METHOD(void, Start);
    DECLARE_INSTANCE_METHOD(void, Update);

    DECLARE_INSTANCE_FIELD(UnityEngine::Color, defaultColor);
    DECLARE_INSTANCE_FIELD(UnityEngine::Color, hoverColor);
    DECLARE_INSTANCE_FIELD(HMUI::ImageView*, image);
    DECLARE_INSTANCE_FIELD(HMUI::NoTransitionsButton*, button);
)