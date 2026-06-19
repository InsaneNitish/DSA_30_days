//we will create operator overloading for easy writing of physics equations for our engine
#pragma once

struct Vec2
{
    float x,y;

    Vec2() : x(0.0f),y(0.0f) {}
    Vec2(float x_val, float y_val): x(x_val),y(y_val) {}

    Vec2 operator+(const Vec2& other) const {
        return Vec2(x+ other.x,y+other.y);
    }

    Vec2 operator-(const Vec2& other) const {
        return Vec2(x-other.x,y-other.y);
    }

    Vec2 operator*(float scaler) const {
        return Vec2(x*scaler,y*scaler);
    }
};
