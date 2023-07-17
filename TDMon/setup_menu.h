#pragma once

#include <TDMon/application_state.h>
#include <TDMon/constants.h>

namespace tdmon {
template <class ReturnToStateOnCompletion>
class SetupMenu : public ApplicationState {
 public:
  // Inherited via ApplicationState
  void init(tgui::GuiSFML& gui) override {
    setup_group_ = tgui::Group::create();

    setup_form_layout_ = tgui::VerticalLayout::create();
    setup_group_->add(setup_form_layout_);

    ok_button_ = tgui::Button::create(Constants::kOkayButtonText);
    setup_form_layout_->add(ok_button_);

    cancel_button_ = tgui::Button::create(Constants::kCancelButtonText);
    setup_form_layout_->add(cancel_button_);

    gui.add(setup_group_);
  };
  std::unique_ptr<ApplicationState> update() override { return nullptr; };
  void cleanup(tgui::GuiSFML& gui) override { gui.remove(setup_group_); };

 private:
  tgui::Group::Ptr setup_group_ = nullptr;

  tgui::VerticalLayout::Ptr setup_form_layout_ = nullptr;
  tgui::Button::Ptr ok_button_ = nullptr;
  tgui::Button::Ptr cancel_button_ = nullptr;
};
}  // namespace tdmon
