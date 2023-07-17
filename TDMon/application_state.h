#pragma once

#include <TDMon/constants.h>

#include <TGUI/TGUI.hpp>

namespace tdmon {
class ApplicationState {
 public:
  virtual ~ApplicationState() = default;

  virtual void init(tgui::GuiSFML& gui) = 0;

  /**
   * @brief Update this application state.
   * @return Indicate which (if any) application state change should take place. If you want to stay in the same state, return kNull.
   */
  virtual SupportedApplicationStateChanges update() = 0;

  virtual void cleanup(tgui::GuiSFML& gui) = 0;

  virtual SupportedApplicationStateTypes getApplicationStateType() const = 0;
};
}  // namespace tdmon
