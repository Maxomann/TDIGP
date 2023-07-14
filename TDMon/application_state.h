#pragma once

#include <TGUI/TGUI.hpp>

namespace tdmon {
class ApplicationState {
 public:
  virtual ~ApplicationState() = default;

  virtual void init(tgui::GuiSFML& gui) = 0;

  virtual void update() = 0;

  virtual void cleanup(tgui::GuiSFML& gui) = 0;
};
}  // namespace tdmon
