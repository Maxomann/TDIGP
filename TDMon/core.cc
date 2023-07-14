#include <TDMon/core.h>
#include <TDMon/main_menu.h>

#include <SFML/Graphics.hpp>
#include <iostream>

/**
 * @brief The program entry point. This function cannot be placed into the tdmon
 * namespace.
 * @return The program exit code. Always 0 in this application.
 */
int main() {
  tdmon::Core core(std::make_unique<tdmon::MainMenu>());
  core.run();

  return 0;
}

namespace tdmon {
void Core::run() {
  window_.create(sf::VideoMode(600, 600), "Technical Debt Monsters!", sf::Style::Close);
  gui_.setTarget(window_);

  application_state_->init(gui_);

  while (window_.isOpen()) {
    sf::Event event;
    while (window_.pollEvent(event)) {
      gui_.handleEvent(event);

      if (event.type == sf::Event::Closed) window_.close();
    }

    // Update the current application state. If the returned value from the
    // update() function is not nullptr, switch to the new application state.
    if (std::unique_ptr<ApplicationState> new_application_state =
            application_state_->update();
        new_application_state != nullptr) {
      application_state_->cleanup(gui_);
      application_state_ = std::move(new_application_state);
      application_state_->init(gui_);
    }

    window_.clear(sf::Color(186, 186, 186));
    gui_.draw();
    window_.display();
  }

  application_state_->cleanup(gui_);
}
Core::Core(std::unique_ptr<ApplicationState> initial_application_state) {
  application_state_ = std::move(initial_application_state);
}
}  // namespace tdmon
