#include "ImageContentBehaviour.hpp"

DEFINE_TYPE(BetterPause, ImageContentBehaviour);

void BetterPause::ImageContentBehaviour::Start() {
    button = GetComponent<HMUI::NoTransitionsButton*>();
	image = get_transform()->Find("BG")->GetComponent<HMUI::ImageView*>();
}
void BetterPause::ImageContentBehaviour::Update() {
    image->set_color(button->get_selectionState() == HMUI::NoTransitionsButton::SelectionState::Highlighted ? hoverColor : defaultColor);
}