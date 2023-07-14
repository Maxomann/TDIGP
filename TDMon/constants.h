#pragma once

#include <string>

namespace tdmon {
struct Constants {
  static const int kHeadingFontSize = 44;
  static const int kButtonFontSize = 20;

  /* Main Menu */
  static const std::string kApplicationNameLabelText;
  static const std::string kViewMascotButtonText;
  static const std::string kConnectToDataSourcesButtonText;

  /* Setup Menu */
  static const std::string kOkayButtonText;
  static const std::string kCancelButtonText;

};
}  // namespace tdmon
