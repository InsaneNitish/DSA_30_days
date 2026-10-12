#pragma once
#include <cmath> // NEW: Required for square roots

struct Vec2 {
    float x;
    float y;

    Vec2() : x(0.0f), y(0.0f) {}
    Vec2(float x_val, float y_val) : x(x_val), y(y_val) {}

    Vec2 operator+(const Vec2& other) const { return Vec2(x + other.x, y + other.y); }
    Vec2 operator-(const Vec2& other) const { return Vec2(x - other.x, y - other.y); }
    Vec2 operator*(float scalar) const { return Vec2(x * scalar, y * scalar); }

    // NEW TOOL 1: The Dot Product
    // Multiplies the matching axes and sums them up into a single number
    float Dot(const Vec2& other) const {
        return (x * other.x) + (y * other.y);
    }

    // NEW TOOL 2: Length (Magnitude)
    // Uses the Pythagorean theorem to find the actual length of the vector
    float Length() const {
        return std::sqrt(x * x + y * y);
    }

    // NEW TOOL 3: Normalize
    // Shrinks the vector down so its length is exactly 1 (keeps the direction intact)
    Vec2 Normalize() const {
        float len = Length();
        if (len == 0.0f) return Vec2(0.0f, 0.0f); // Safety check to prevent dividing by zero
        return Vec2(x / len, y / len);
    }
};