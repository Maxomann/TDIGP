#pragma once

#include <TDMon/application_state.h>

#include <string>

namespace tdmon {
class MainMenu : public ApplicationState {
 public:
  static const std::string kApplicationNameLabelText;
  static const std::string kViewMascotButtonText;
  static const std::string kConnectToDataSourcesButtonText;

  // Inherited via ApplicationState
  void init(tgui::GuiSFML& gui) override;
  void update() override;
  void cleanup(tgui::GuiSFML& gui) override;

 private:
  tgui::Group::Ptr main_menu_group_ = nullptr;
  tgui::Label::Ptr main_name_label_ = nullptr;

  // TODO TODO
  tgui::HorizontalLayout::Ptr button_layout_ = nullptr;
  tgui::Button::Ptr view_mascot_button_ = nullptr;
  tgui::Button::Ptr connect_to_data_sources_button = nullptr;
};
}  // namespace tdmon
