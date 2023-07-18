#pragma once

#include <TDMon/application_state.h>
#include <TDMon/constants.h>
#include <TDMon/technical_debt_dataset_access_information_container.h>

namespace tdmon {
class TechnicalDebtDatasetSetupMenu : public ApplicationState {
 public:
  TechnicalDebtDatasetSetupMenu(
      TechnicalDebtDatasetAccessInformationContainer& information_destination);

  // Inherited via ApplicationState
  void init(tgui::GuiSFML& gui) override;
  SupportedApplicationStateChanges update() override;
  void cleanup(tgui::GuiSFML& gui) override;
  SupportedApplicationStateTypes getApplicationStateType() const override;

 private:
  SupportedApplicationStateChanges next_application_state_change_ =
      SupportedApplicationStateChanges::kNull;

  tgui::Group::Ptr setup_group_ = nullptr;

  tgui::VerticalLayout::Ptr setup_form_layout_ = nullptr;

  tgui::Label::Ptr path_to_database_label = nullptr;
  tgui::EditBox::Ptr path_to_database_input = nullptr;

  tgui::Button::Ptr ok_button_ = nullptr;
  tgui::Button::Ptr cancel_button_ = nullptr;

  TechnicalDebtDatasetAccessInformationContainer& information_destination_;
};
}  // namespace tdmon
