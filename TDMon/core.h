#pragma once

#include <TGUI/TGUI.hpp>
#include <TGUI/Backends/SFML.hpp>

#include "TDMon/application_state.h"

namespace tdmon {
class Core {
 public:
  /**
   * @brief run the application
   */
  void run();

 private:
  sf::RenderWindow window_;

  tgui::GuiSFML gui_;


};
}  // namespace tdmon
