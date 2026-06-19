// Here, we just declare what a RigidBody is and what it can do. We do not write the logic for the constructor here. We are just giving the compiler the blueprint.

#pragma once
#include "Vec2.h"

struct RigidBody{
    //properties
    Vec2 position;
    Vec2 velocity;
    Vec2 acceleration;

    float mass;
    float inverse_mass;

    //only constructor is defined here other logic will be defined in cpp file
    RigidBody(float start_x,float start_y,float obj_mass);

    //physics functions

    void AddForce(const Vec2& force);

    void Integrate(float dt);
};