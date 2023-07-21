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

#include <string>

namespace tdmon {
struct UiConstants {
  static const int kHeadingFontSize = 44;
  static const int kLabelFontSize = 20;
  static const int kButtonFontSize = 20;
  static const int kEditBoxFontSize = 20;

  /* Main Menu */
  static const std::string kApplicationNameLabelText;
  static const std::string kViewMascotButtonText;
  static const std::string kConnectToDataSourcesButtonText;

  /* Technical Debt Dataset Setup Menu */
  static const std::string kOkayButtonText;
  static const std::string kCancelButtonText;
  static const std::string kPathToDatabaseInputLabelText;
  static const std::string kUserIdentifierInputLabelText;

  /* Observe Menu */
  static const std::string kBackButtonText;
  static const std::string kRefreshButtonText;
};

/**
 * @brief The supported application states.
 */
enum class SupportedApplicationStateTypes {
  kNull,  // indicate that no application state is active
  kMainMenu,
  kSetupMenu,
  kObserveMenu
};

/**
 * @brief The supported application state changes.
 */
enum class SupportedApplicationStateChanges {
  kNull,         // request to stay in the current state
  kPrevious,     // request to return to the previous state
  kMainMenu,     // request to open the main menu
  kSetupMenu,    // request to open the setup menu
  kObserveMenu,  // request to open the observe TDMon menu
  kClose         // request to close the application
};

}  // namespace tdmon
