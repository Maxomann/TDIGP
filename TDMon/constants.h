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
/**
 * @brief Global UI constants for the application. E.g. text strings or font
 * size.
 */
struct UiConstants {
  /**
   * @brief Font size for headings
   */
  static const int kHeadingFontSize = 44;
  /**
   * @brief Font size for labels
   */
  static const int kLabelFontSize = 20;
  /**
   * @brief Font size for text in buttons
   */
  static const int kButtonFontSize = 20;
  /**
   * @brief Font size for text in edit boxes
   */
  static const int kEditBoxFontSize = 20;

  /*** Main Menu ***/

  /**
   * @brief The application name label text string
   */
  static const std::string kApplicationNameLabelText;
  /**
   * @brief The view mascot (td-mon) button text string
   */
  static const std::string kViewMascotButtonText;
  /**
   * @brief The 'connect to data sources' button text string
   */
  static const std::string kConnectToDataSourcesButtonText;

  /*** Technical Debt Dataset Setup Menu ***/

  /**
   * @brief The okay button text string
   */
  static const std::string kOkayButtonText;
  /**
   * @brief The cancel button text string
   */
  static const std::string kCancelButtonText;
  /**
   * @brief The 'path-to-database' input label text string
   */
  static const std::string kPathToDatabaseInputLabelText;
  /**
   * @brief The 'user-identifier' input label text string
   */
  static const std::string kUserIdentifierInputLabelText;

  /*** Observe Menu ***/

  /**
   * @brief The back button text string
   */
  static const std::string kBackButtonText;
  /**
   * @brief The refresh button text string
   */
  static const std::string kRefreshButtonText;
};

/**
 * @brief The supported application states.
 *
 * This is required to allow dependency injection through templates in the core,
 * while still being able to switch between different 'types' of states.
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
