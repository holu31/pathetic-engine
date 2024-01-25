#include <core/input.hpp>
#include <SFML/Graphics.hpp>

bool Input::isKeyPressed(int scancode) {
    sf::Keyboard::Key key = static_cast<sf::Keyboard::Key>(scancode);
    return sf::Keyboard::isKeyPressed(key);
}