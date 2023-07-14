#pragma once

#include <TDMon/application_state.h>

#include <string>

namespace tdmon {
class MainMenu : public ApplicationState {
 public:
  static const std::string kApplicationNameLabelText;
  static const std::string kViewMascotButtonText;
  static const std::string kConnectToDataSourcesButtonText;

  static const int kHeadingFontSize = 44;
  static const int kButtonFontSize = 20;

  // Inherited via ApplicationState
  void init(tgui::GuiSFML& gui) override;
  std::unique_ptr<ApplicationState> update() override;
  void cleanup(tgui::GuiSFML& gui) override;

 private:
  tgui::Group::Ptr main_menu_group_ = nullptr;
  tgui::Label::Ptr main_name_label_ = nullptr;

  tgui::VerticalLayout::Ptr button_layout_ = nullptr;
  tgui::Button::Ptr view_mascot_button_ = nullptr;
  tgui::Button::Ptr connect_to_data_sources_button_ = nullptr;
};
}  // namespace tdmon
