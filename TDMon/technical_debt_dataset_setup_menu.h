/*********************************
 *
 * TD-Mon - Copyright 2023 (c) Kay Leon Gonschior
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the “Software”), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED “AS IS”,
 * WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED
 * TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE
 * FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
 * TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR
 * THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 *
 *********************************/

#pragma once

#include <TDMon/application_state.h>
#include <TDMon/connectable_to_data_sources.h>
#include <TDMon/constants.h>
#include <TDMon/technical_debt_dataset_access_information_container.h>

#include <concepts>
#include <iostream>

namespace tdmon {
/**
 * @brief This setup menu can set up any td mon factory, as long as it
 * implements the required interfaces
 * @tparam TdMonFactoryToSetup Must inherit from
 * TechnicalDebtDatasetAccessInformationContainer and ConnectableToDataSources
 *
 */
template <class TdMonFactoryToSetup>
  requires std::derived_from<TdMonFactoryToSetup,
                             TechnicalDebtDatasetAccessInformationContainer> &&
           std::derived_from<TdMonFactoryToSetup, ConnectableToDataSources>
class TechnicalDebtDatasetSetupMenu : public ApplicationState {
 public:
  TechnicalDebtDatasetSetupMenu(TdMonFactoryToSetup& factory_to_setup)
      : factory_to_setup_(factory_to_setup) {}

  // Inherited via ApplicationState
  void init(tgui::GuiSFML& gui) override {
    setup_group_ = tgui::Group::create();

    setup_form_layout_ = tgui::VerticalLayout::create();
    setup_group_->add(setup_form_layout_);

    path_to_database_label_ =
        tgui::Label::create(UiConstants::kPathToDatabaseInputLabelText);
    path_to_database_label_->setTextSize(UiConstants::kLabelFontSize);
    setup_form_layout_->add(path_to_database_label_);

    path_to_database_input_ = tgui::EditBox::create();
    path_to_database_input_->setTextSize(UiConstants::kEditBoxFontSize);
    setup_form_layout_->add(path_to_database_input_);

    user_identifier_label =
        tgui::Label::create(UiConstants::kUserIdentifierInputLabelText);
    user_identifier_label->setTextSize(UiConstants::kLabelFontSize);
    setup_form_layout_->add(user_identifier_label);

    user_identifier_input = tgui::EditBox::create();
    user_identifier_input->setTextSize(UiConstants::kEditBoxFontSize);
    setup_form_layout_->add(user_identifier_input);

    ok_button_ = tgui::Button::create(UiConstants::kOkayButtonText);
    ok_button_->setTextSize(UiConstants::kButtonFontSize);
    ok_button_->onPress.connect([&]() {
      // retrieve the path to the database from the EditBox as a tgui::String
      const tgui::String& input_string = path_to_database_input_->getText();
      // convert the string to a path object
      std::filesystem::path input_path(input_string.toAnsiString());

      // set the database path in the information destination
      factory_to_setup_.setDatabasePath(input_path);

      // set the user identifier to use when querying the sql database
      factory_to_setup_.setUserIdentifier(user_identifier_input->getText().toAnsiString());

      // check if all needed information is available
      if (factory_to_setup_.isRequiredDataAccessInformationAvailable()) {
        // connect to data sources
        try {
          factory_to_setup_.connectToDataSources();

          std::cout << "connected to data sources successfully" << std::endl;

          // on success, return to previous menu
          next_application_state_change_ =
              SupportedApplicationStateChanges::kPrevious;
        } catch (std::exception e) {
          // if connecting to data sources fails
          std::cout
              << "error while connection to data sources. please check if "
                 "the entered information is correct"
              << std::endl;
        }
      } else {
        // not all required information has been entered
        std::cout << "isRequiredDataAccessInformationAvailable == false"
                  << std::endl;
      }
    });
    setup_form_layout_->add(ok_button_);

    cancel_button_ = tgui::Button::create(UiConstants::kCancelButtonText);
    cancel_button_->setTextSize(UiConstants::kButtonFontSize);
    cancel_button_->onPress.connect([&]() {
      next_application_state_change_ =
          SupportedApplicationStateChanges::kPrevious;
    });
    setup_form_layout_->add(cancel_button_);

    gui.add(setup_group_);
  };

  SupportedApplicationStateChanges update() override {
    return next_application_state_change_;
  };

  void cleanup(tgui::GuiSFML& gui) override { gui.remove(setup_group_); };

  SupportedApplicationStateTypes getApplicationStateType() const override {
    return SupportedApplicationStateTypes::kSetupMenu;
  };

 private:
  SupportedApplicationStateChanges next_application_state_change_ =
      SupportedApplicationStateChanges::kNull;

  tgui::Group::Ptr setup_group_ = nullptr;

  tgui::VerticalLayout::Ptr setup_form_layout_ = nullptr;

  tgui::Label::Ptr path_to_database_label_ = nullptr;
  tgui::EditBox::Ptr path_to_database_input_ = nullptr;

  tgui::Label::Ptr user_identifier_label = nullptr;
  tgui::EditBox::Ptr user_identifier_input = nullptr;

  tgui::Button::Ptr ok_button_ = nullptr;
  tgui::Button::Ptr cancel_button_ = nullptr;

  TdMonFactoryToSetup& factory_to_setup_ = nullptr;
};
}  // namespace tdmon
