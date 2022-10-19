#pragma once

namespace kart {

    /**
     * Immutable Vector2F class. All operators act elementwise.
     */
    class Vector2 {
    private:
        float x, y;
    public:
        Vector2(float x, float y);

        Vector2();

        float getX();
        float getY();

        Vector2 operator+(const Vector2&) const;

        Vector2 operator-(const Vector2&) const;

        Vector2 operator/(float) const;

        Vector2 operator/(int) const;

        Vector2 operator/(const Vector2&) const;

        Vector2 operator*(float) const;

        Vector2 operator*(int) const;

        Vector2 operator*(const Vector2&) const;

        Vector2 absolute() const;

        float len() const;

        float dist(const Vector2&) const;

        Vector2 norm() const;

        float crossProductMagnitude(const Vector2&) const;

        float dot(const Vector2&) const;
    };
}