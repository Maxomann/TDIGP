#include <TDMon/constants.h>
#include <TDMon/setup.h>

namespace tdmon {
void Setup::init(tgui::GuiSFML& gui) {
  setup_group_ = tgui::Group::create();

  setup_form_layout_ = tgui::VerticalLayout::create();
  setup_group_->add(setup_form_layout_);

  ok_button_ = tgui::Button::create(Constants::kOkayButtonText);
  setup_form_layout_->add(ok_button_);

  cancel_button_ = tgui::Button::create(Constants::kCancelButtonText);
  setup_form_layout_->add(cancel_button_);

  gui.add(setup_group_);
}

std::unique_ptr<ApplicationState> Setup::update() { return nullptr; }

void Setup::cleanup(tgui::GuiSFML& gui) { gui.remove(setup_group_); }
}  // namespace tdmon