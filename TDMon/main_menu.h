#pragma once

#include <TDMon/application_state.h>
#include <TDMon/constants.h>

#include <string>

namespace tdmon {
class MainMenu : public ApplicationState {
 public:
  // Inherited via ApplicationState
  void init(tgui::GuiSFML& gui) override;
  SupportedApplicationStateChanges update() override;
  void cleanup(tgui::GuiSFML& gui) override;
  SupportedApplicationStateTypes getApplicationStateType() const override;

 private:
  tgui::Group::Ptr main_menu_group_ = nullptr;
  tgui::Label::Ptr main_name_label_ = nullptr;

  tgui::VerticalLayout::Ptr button_layout_ = nullptr;
  tgui::Button::Ptr view_mascot_button_ = nullptr;
  tgui::Button::Ptr connect_to_data_sources_button_ = nullptr;
};
}  // namespace tdmon
