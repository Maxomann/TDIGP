#pragma once

#include <TDMon/application_state.h>

#include <TGUI/Backends/SFML.hpp>
#include <TGUI/TGUI.hpp>
#include <memory>

namespace tdmon {
class Core {
 public:
  Core(std::unique_ptr<ApplicationState> initial_application_state);

  /**
   * @brief run the application
   */
  void run();

 private:
  sf::RenderWindow window_;
  tgui::GuiSFML gui_;

  std::unique_ptr<ApplicationState> application_state_;
};
}  // namespace tdmon
