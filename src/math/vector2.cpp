#include <math/vector2.hpp>
#include <cmath>

Vector2::Vector2() {
    Vector2::Vector2(0, 0);
}

Vector2::Vector2(float x, float y) {
    this->x = x;
    this->y = y;
}

void Vector2::setTransform(float x, float y) {
    this->x = x;
    this->y = y;
}

float Vector2::length() {
    return std::sqrt(x*x + y*y);
}

void Vector2::normalize() {
    float length = this->length();
    if (length == 0) return;

    x /= length;
    y /= length;
}

Vector2 Vector2::operator *(const Vector2 &vec2) {
    return Vector2(x * vec2.x, y * vec2.y);
}
