#pragma once

#include <string>

namespace tdmon {
struct Constants {
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

  /* Observe Menu */
  static const std::string kBackButtonText;
  static const std::string kRefreshButtonText;
};

/**
 * @brief The supported application states.
*/
enum class SupportedApplicationStateTypes {
	kNull, // indicate that no application state is active
	kMainMenu,
	kSetupMenu,
	kObserveMenu
};

/**
 * @brief The supported application state changes.
*/
enum class SupportedApplicationStateChanges {
	kNull, // request to stay in the current state
	kPrevious, // request to return to the previous state
	kMainMenu, // request to open the main menu
	kSetupMenu, // request to open the setup menu
	kObserveMenu, // request to open the observe TDMon menu
	kClose // request to close the application
};
}  // namespace tdmon
