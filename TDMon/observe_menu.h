#pragma once

#include <TDMon/application_state.h>
#include <TDMon/td_mon_cache.h>
#include <TDMon/td_mon_factory.h>

namespace tdmon {
class ObserveMenu : public ApplicationState {
 public:
  static const std::string kLowLevelTexturePath;
  static const std::string kMediumLevelTexturePath;
  static const std::string kHighLevelTexturePath;

  ObserveMenu(TdMonCache& tdmon_cache, TdMonFactory& tdmon_factory);

  // Inherited via ApplicationState
  void init(tgui::GuiSFML& gui) override;
  SupportedApplicationStateChanges update() override;
  void cleanup(tgui::GuiSFML& gui) override;
  SupportedApplicationStateTypes getApplicationStateType() const override;

 private:
  TdMonCache& tdmon_cache_;
  TdMonFactory& tdmon_factory_;

  sf::Texture tdmon_visual_representation_;

  SupportedApplicationStateChanges next_application_state_change_ =
      SupportedApplicationStateChanges::kNull;

  tgui::Group::Ptr observe_menu_group_ = nullptr;
  tgui::Button::Ptr back_button_ = nullptr;
  tgui::Button::Ptr refresh_button_ = nullptr;

  tgui::Picture::Ptr tdmon_picture_ = nullptr;  // todo

  tgui::Label::Ptr tdmon_data_label_ = nullptr;

  void refreshTdMon(bool prefer_cache = false);
};
}  // namespace tdmon
