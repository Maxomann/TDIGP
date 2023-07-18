#pragma once

#include <TDMon/application_state.h>

namespace tdmon {
class ObserveMenu : public ApplicationState {
 public:
  // Inherited via ApplicationState
  void init(tgui::GuiSFML& gui) override;
  SupportedApplicationStateChanges update() override;
  void cleanup(tgui::GuiSFML& gui) override;
  SupportedApplicationStateTypes getApplicationStateType() const override;

 private:
  SupportedApplicationStateChanges next_application_state_change_ =
      SupportedApplicationStateChanges::kNull;

  tgui::Group::Ptr observe_menu_group_ = nullptr;
  tgui::Button::Ptr back_button_ = nullptr;
  tgui::Button::Ptr refresh_button_ = nullptr;

  tgui::Picture::Ptr tdmon_picture_ = nullptr;// todo

  tgui::Label::Ptr tdmon_data_label_ = nullptr;

  void refreshTdMon();
};
}  // namespace tdmon
