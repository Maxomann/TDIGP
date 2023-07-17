#pragma once

#include <TGUI/TGUI.hpp>

namespace tdmon {
class ApplicationState {
 public:
  virtual ~ApplicationState() = default;

  virtual void init(tgui::GuiSFML& gui) = 0;

  /**
   * @brief Update this application state.
   * @return Return nullptr to continue running the currently active state.
   * Return a valid ApplicationState object to signal the core to switch the
   * current state to the new (returned) one.
   * Note: Do not call the init() method before returning the ApplicationState.
   * This is done automatically in the Core.
   */
  virtual std::unique_ptr<ApplicationState> update() = 0;

  virtual void cleanup(tgui::GuiSFML& gui) = 0;
};
}  // namespace tdmon
