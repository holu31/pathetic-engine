#include <core/clock.hpp>
#include <SFML/Graphics.hpp>

sf::Clock m_clock;
float m_deltaTime = 0.0f;

float Clock::deltaTime() {
    return m_deltaTime;
}

void Clock::timeUpdate() {
    m_deltaTime = m_clock.restart().asSeconds();
}