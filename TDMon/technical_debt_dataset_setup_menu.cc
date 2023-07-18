#include <TDMon/constants.h>
#include <TDMon/technical_debt_dataset_setup_menu.h>

namespace tdmon {
TechnicalDebtDatasetSetupMenu::TechnicalDebtDatasetSetupMenu(
    TechnicalDebtDatasetAccessInformationContainer& information_destination)
    : information_destination_(information_destination) {}

void TechnicalDebtDatasetSetupMenu::init(tgui::GuiSFML& gui) {
  setup_group_ = tgui::Group::create();

  setup_form_layout_ = tgui::VerticalLayout::create();
  setup_group_->add(setup_form_layout_);

  path_to_database_label =
      tgui::Label::create(Constants::kPathToDatabaseInputLabelText);
  path_to_database_label->setTextSize(Constants::kLabelFontSize);
  setup_form_layout_->add(path_to_database_label);

  path_to_database_input = tgui::EditBox::create();
  path_to_database_input->setTextSize(Constants::kEditBoxFontSize);
  setup_form_layout_->add(path_to_database_input);

  ok_button_ = tgui::Button::create(Constants::kOkayButtonText);
  ok_button_->setTextSize(Constants::kButtonFontSize);
  ok_button_->onPress.connect([&]() {
    // retrieve the path to the database from the EditBox as a tgui::String
    const tgui::String& input_string = path_to_database_input->getText();
    // convert the string to a path object
    std::filesystem::path input_path(input_string.toAnsiString());

    // set the database path in the information destination
    information_destination_.setDatabasePath(input_path);
  });
  setup_form_layout_->add(ok_button_);

  cancel_button_ = tgui::Button::create(Constants::kCancelButtonText);
  cancel_button_->setTextSize(Constants::kButtonFontSize);
  cancel_button_->onPress.connect([&]() {
    next_application_state_change_ =
        SupportedApplicationStateChanges::kPrevious;
  });
  setup_form_layout_->add(cancel_button_);

  gui.add(setup_group_);
}

SupportedApplicationStateChanges TechnicalDebtDatasetSetupMenu::update() {
  return next_application_state_change_;
}

void TechnicalDebtDatasetSetupMenu::cleanup(tgui::GuiSFML& gui) {
  gui.remove(setup_group_);
}

SupportedApplicationStateTypes
tdmon::TechnicalDebtDatasetSetupMenu::getApplicationStateType() const {
  return SupportedApplicationStateTypes::kSetupMenu;
}
}  // namespace tdmon
