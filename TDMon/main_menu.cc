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

#include "main_menu.h"

// Inherited via ApplicationState

namespace tdmon {
void MainMenu::init(tgui::GuiSFML& gui) {
  main_menu_group_ = tgui::Group::create();
  main_name_label_ = tgui::Label::create(UiConstants::kApplicationNameLabelText);
  main_name_label_->setTextSize(UiConstants::kHeadingFontSize);
  main_name_label_->setPosition("(parent.width - width) / 2", 20.0f);
  main_menu_group_->add(main_name_label_);

  button_layout_ = tgui::VerticalLayout::create();
  button_layout_->setSize({"70%", 200.0f});
  button_layout_->setPosition("(parent.size - size) / 2");

  view_mascot_button_ = tgui::Button::create(UiConstants::kViewMascotButtonText);
  view_mascot_button_->setTextSize(UiConstants::kButtonFontSize);
  view_mascot_button_->onPress.connect([&]() {
    next_application_state_change_ =
        SupportedApplicationStateChanges::kObserveMenu;
  });
  button_layout_->add(view_mascot_button_);
  connect_to_data_sources_button_ =
      tgui::Button::create(UiConstants::kConnectToDataSourcesButtonText);
  connect_to_data_sources_button_->setTextSize(UiConstants::kButtonFontSize);
  connect_to_data_sources_button_->onPress.connect([&]() {
    next_application_state_change_ =
        SupportedApplicationStateChanges::kSetupMenu;
  });
  button_layout_->add(connect_to_data_sources_button_);

  // insert space *after* the buttons have been added
  button_layout_->insertSpace(1, 0.5f);
  main_menu_group_->add(button_layout_);

  gui.add(main_menu_group_);
}

SupportedApplicationStateChanges MainMenu::update() {
  return next_application_state_change_;
}

void MainMenu::cleanup(tgui::GuiSFML& gui) { gui.remove(main_menu_group_); }
SupportedApplicationStateTypes MainMenu::getApplicationStateType() const {
  return SupportedApplicationStateTypes::kMainMenu;
}
}  // namespace tdmon
