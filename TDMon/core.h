#pragma once

#include <TDMon/application_state.h>
#include <TDMon/constants.h>

#include <SFML/Graphics.hpp>
#include <TGUI/Backends/SFML.hpp>
#include <TGUI/TGUI.hpp>
#include <iostream>
#include <memory>

namespace tdmon {
template <class MainMenuType, class SetupMenuType, class ObserveMenuType>
class Core {
 public:
  Core() { application_state_ = std::make_unique<MainMenuType>(); };

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

      // update the application state
      // if false is returned, close the application
      if (!updateApplicationState()) {
        window_.close();
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

  /**
   * @brief The previous application state. This is cached to support the
   * kPrevious state change.
   */
  SupportedApplicationStateTypes previous_state_type_ =
      SupportedApplicationStateTypes::kNull;
  std::unique_ptr<ApplicationState> application_state_;

  /**
   * @brief Update the current application state. May trigger a switch to a different application state, if the current state requests it.
   * @return return true, if the application should continue to run. Return
   * false, if the application should be closed.
   */
  bool updateApplicationState() {
    // Update the current application state and handle possibly requested state
    // changes
    SupportedApplicationStateChanges requested_state_change =
        application_state_->update();

    switch (requested_state_change) {
      case tdmon::SupportedApplicationStateChanges::kNull:
        // do nothing, continue with current state
        break;
      case tdmon::SupportedApplicationStateChanges::kPrevious:
        if (previous_state_type_ != SupportedApplicationStateTypes::kNull) {
          switchToApplicationState(previous_state_type_);
        } else {
          throw std::exception("previous application state is kNull");
        }
        break;
      case tdmon::SupportedApplicationStateChanges::kMainMenu:
        switchToApplicationState(SupportedApplicationStateTypes::kMainMenu);
        break;
      case tdmon::SupportedApplicationStateChanges::kSetupMenu:
        switchToApplicationState(SupportedApplicationStateTypes::kSetupMenu);
        break;
      case tdmon::SupportedApplicationStateChanges::kObserveMenu:
        switchToApplicationState(SupportedApplicationStateTypes::kObserveMenu);
        break;
      case tdmon::SupportedApplicationStateChanges::kClose:
        return false;
        break;
      default:
        throw std::exception("requested state change not supported");
        break;
    }

    return true;
  };

  /**
   * @brief Switch to a different application state. Also, update
   * previous_state_type_.
   * @param state The new state type to switch to
   */
  void switchToApplicationState(SupportedApplicationStateTypes new_state_type) {
    std::unique_ptr<ApplicationState> new_application_state = nullptr;

    // Construct new state
    switch (new_state_type) {
      case tdmon::SupportedApplicationStateTypes::kNull:
        throw std::exception("cannot switch to application state type kNull");
        break;
      case tdmon::SupportedApplicationStateTypes::kMainMenu:
        new_application_state = std::make_unique<MainMenuType>();
        break;
      case tdmon::SupportedApplicationStateTypes::kSetupMenu:
        new_application_state = std::make_unique<SetupMenuType>();
        break;
      case tdmon::SupportedApplicationStateTypes::kObserveMenu:
        new_application_state = std::make_unique<ObserveMenuType>();
        break;
      default:
        throw std::exception("new_state_type not supported");
        break;
    }

    // record previous state type
    previous_state_type_ = application_state_->getApplicationStateType();

    // change to the new state
    if (new_application_state != nullptr) {
      // run cleanup on current applications state
      application_state_->cleanup(gui_);
      // switch application state
      application_state_ = std::move(new_application_state);
      // run init on new application state
      application_state_->init(gui_);
    } else {
      throw std::exception("new_application_state is nullptr");
    }
  }
};
}  // namespace tdmon
