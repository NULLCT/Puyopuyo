#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System.hpp>
#include <SFML/System/Mutex.hpp>
#include <SFML/System/Thread.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/ContextSettings.hpp>
#include <cmath>
#include <iostream>
#include <iterator>
#include <vector>
using namespace std;

class RotateCircle {
public:
  RotateCircle() : shape(100.f) {
    shape.setFillColor(sf::Color::Black);
    shape.setOutlineThickness(1.f);
    shape.setOutlineColor(sf::Color(255, 255, 255));
    shape.setOrigin(100, 100);
    shape.setPosition(sf::Vector2f(100, 100));
    shape.setPointCount(50);
  }
  sf::CircleShape getShape() {
    shape.setScale(sf::Vector2f(sin(flame / 10.0), cos(flame / 10.0)));
    flame++;

    return shape;
  }

  int flame = 0;

private:
  sf::CircleShape shape;
};

int main() {
  sf::ContextSettings consetting;
  consetting.antialiasingLevel = 8;
  sf::RenderWindow window(sf::VideoMode(200, 200), "<3", sf::Style::None,
                          consetting);
  window.setFramerateLimit(60);

  vector<RotateCircle> circles(1);
  for (int i = 0; i < circles.size(); i++) {
    circles[i].flame = i * 200;
  }

  while (window.isOpen()) {
    sf::Event event;
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed)
        window.close();
    }

    for (auto &i : circles)
      window.draw(i.getShape());
    window.display();
  }

  return 0;
}
