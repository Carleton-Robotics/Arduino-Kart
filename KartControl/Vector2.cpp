//
// Created by Zimri on 9/30/2022.
//

#include "Vector2.h"

float kart::Vector2::Vector2() : x(0.0f), y(0.0f) {}

float kart::Vector2::Vector2(float x, float y) : x(x), y(y) {}

float kart::Vector2::getX() {
    return x;
}

float kart::Vector2::getY() {
    return y;
}

float kart::Vector2::Dist(const Vector2 &o) const {
    return sqrt((x - o.getX()) * (x - o.getX()) + (y - o.getY()) * (y - o.getY()));
}

float kart::Vector2::Len() const {
    return sqrt(x * x + y * y);
}

Vector2 kart::Vector2::operator*(int i) const {
    return {x * i, y * i};
}

Vector2 kart::Vector2::operator*(float f) const {
    return {x * f, y * f};
}

Vector2 kart::Vector2::operator*(const Vector2 &o) const {
    return {x * o.getX(), y * o.getY()};
}

Vector2 kart::Vector2::operator+(const Vector2 &o) const {
    return {x + o.getX(), y + o.getY()};
}

Vector2 kart::Vector2::operator-(const Vector2 &o) const {
    return {x - o.getX(), y - o.getY()};
}

Vector2 kart::Vector2::operator/(float f) const {
    return {x / f, y / f};
}

Vector2 kart::Vector2::operator/(int i) const {
    return {x / i, y / i};
}

Vector2 kart::Vector2::operator/(const Vec &o) const {
    return {x / o.getX(), y / o.getY()};
}

Vector2 kart::Vector2::Dot(const Vec &o) const {
    return x * o.getX() + y * o.getY();
}

Vector2 kart::Vector2::Abs() const {
    return {abs(x), abs(y)};
}

float kart::Vector2::CrossProductMagnitude(const Vector2 &o) const {
    return x * o.getY() - y * o.getX();
}

Vector2 kart::Vector2::Norm() const {
    float mag = Len();
    return {x / Mag, y / Mag};
}