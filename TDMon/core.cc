#include "core.h"

#include <SFML/Graphics.hpp>
#include <iostream>

int main() {
  tdm::Core core;
  core.run();
}

namespace tdm {
void Core::run() {
  window_.create(sf::VideoMode(600, 600), "Technical Debt Monsters!");
  gui_.setTarget(window_);

  sf::CircleShape shape(100.f);
  shape.setFillColor(sf::Color::Green);

  while (window_.isOpen()) {
    sf::Event event;
    while (window_.pollEvent(event)) {
      gui_.handleEvent(event);

      if (event.type == sf::Event::Closed) window_.close();
    }

    window_.clear(sf::Color(186,186,186));
    window_.draw(shape);
    window_.display();
  }
}
}  // namespace tdm
