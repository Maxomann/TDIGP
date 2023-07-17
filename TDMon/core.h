#pragma once

#include <TDMon/application_state.h>

#include <SFML/Graphics.hpp>
#include <TGUI/Backends/SFML.hpp>
#include <TGUI/TGUI.hpp>
#include <iostream>
#include <memory>

namespace tdmon {
template <class InitialApplicationStateType>
class Core {
 public:
  Core() {
    application_state_ = std::make_unique<InitialApplicationStateType>();
  };

  /**
   * @brief run the application
   */
  void run() {
    window_.create(sf::VideoMode(600, 600), "Technical Debt Monsters!",
                   sf::Style::Close);
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
  };

 private:
  sf::RenderWindow window_;
  tgui::GuiSFML gui_;

  std::unique_ptr<ApplicationState> application_state_;
};
}  // namespace tdmon
