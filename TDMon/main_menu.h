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
#include <TDMon/constants.h>

#include <string>

namespace tdmon {
/**
 * @brief The main menu ApplicationState. Responsible for allowing the user to
 * select which Use-Case to access.
 */
class MainMenu : public ApplicationState {
 public:
  // Inherited via ApplicationState

  /**
   * @brief Implementation of the init function from ApplicationState.
   * Initializes the gui and gui callbacks.
   * @param gui The gui.
   */
  void init(tgui::GuiSFML& gui) override;

  /**
   * @brief Implementation of the update function from ApplicationState
   * @return The application state to change to
   */
  SupportedApplicationStateChanges update() override;

  /**
   * @brief Implementation of the cleanup function from ApplicationState.
   * Removes the gui elements that were added in init()
   * @param gui The gui
   */
  void cleanup(tgui::GuiSFML& gui) override;

  /**
   * @brief Get this classes application state type
   * @return The application state type
   */
  SupportedApplicationStateTypes getApplicationStateType() const override;

 private:
  /**
   * @brief Store the next application state change to be requested in update().
   * kNull by default (stay in this state). Ui callbacks may change this value
   * dependin on which button is pressed.
   */
  SupportedApplicationStateChanges next_application_state_change_ =
      SupportedApplicationStateChanges::kNull;

  /**
   * @brief The main menu group ui element
  */
  tgui::Group::Ptr main_menu_group_ = nullptr;
  /**
   * @brief The main name label ui element
  */
  tgui::Label::Ptr main_name_label_ = nullptr;

  /**
   * @brief The button layout ui element
  */
  tgui::VerticalLayout::Ptr button_layout_ = nullptr;
  /**
   * @brief The view mascot (td-mon) button ui element 
  */
  tgui::Button::Ptr view_mascot_button_ = nullptr;
  /**
   * @brief The 'connect to data sources' (setup) button ui element
  */
  tgui::Button::Ptr connect_to_data_sources_button_ = nullptr;
};
}  // namespace tdmon
