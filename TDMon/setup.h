#pragma once

#include <TDMon/application_state.h>

namespace tdmon {
class Setup : public ApplicationState {
 public:

  // Inherited via ApplicationState
  void init(tgui::GuiSFML& gui) override;
  std::unique_ptr<ApplicationState> update() override;
  void cleanup(tgui::GuiSFML& gui) override;

 private:
  tgui::Group::Ptr setup_group_ = nullptr;

  tgui::VerticalLayout::Ptr setup_form_layout_ = nullptr;
  tgui::Button::Ptr ok_button_ = nullptr;
  tgui::Button::Ptr cancel_button_ = nullptr;
};
}  // namespace tdmon
