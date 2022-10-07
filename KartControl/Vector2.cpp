//
// Created by Zimri on 9/30/2022.
//

#include "Vector2.h"
#include <Arduino.h>
using namespace kart;

Vector2::Vector2() : x(0.0f), y(0.0f) {}

Vector2::Vector2(float x, float y) : x(x), y(y) {}

float Vector2::getX() {
    return x;
}

float Vector2::getY() {
    return y;
}

float Vector2::dist(const Vector2 &o) const {
    return sqrt((x - o.getX()) * (x - o.getX()) + (y - o.getY()) * (y - o.getY()));
}

float Vector2::len() const {
    return sqrt(x * x + y * y);
}

Vector2 Vector2::operator*(int i) const {
    return {x * i, y * i};
}

Vector2 Vector2::operator*(float f) const {
    return {x * f, y * f};
}

Vector2 Vector2::operator*(const Vector2 &o) const {
    return {x * o.getX(), y * o.getY()};
}

Vector2 Vector2::operator+(const Vector2 &o) const {
    return {x + o.getX(), y + o.getY()};
}

Vector2 Vector2::operator-(const Vector2 &o) const {
    return {x - o.getX(), y - o.getY()};
}

Vector2 Vector2::operator/(float f) const {
    return {x / f, y / f};
}

Vector2 Vector2::operator/(int i) const {
    return {x / i, y / i};
}

Vector2 Vector2::operator/(const Vector2 &o) const {
    return {x / o.getX(), y / o.getY()};
}

float Vector2::dot(const Vector2 &o) const {
    return x * o.getX() + y * o.getY();
}

Vector2 Vector2::absolute() const {
    return {abs(x), abs(y)};
}

float Vector2::crossProductMagnitude(const Vector2 &o) const {
    return x * o.getY() - y * o.getX();
}

Vector2 Vector2::norm() const {
    float mag = len();
    return {x / mag, y / mag};
}