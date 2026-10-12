//core logic for rigid bodies
#include "RigidBody.h"

RigidBody::RigidBody(float start_x,float start_y,float obj_mass){
    position = Vec2(start_x,start_y);
    velocity = Vec2(0.0f,0.0f);
    acceleration = Vec2(0.0f,0.0f);

    mass = obj_mass;

    if(mass==0.0f){
        inverse_mass = 0.0f;
    }else{
        inverse_mass = 1.0f/mass;
    }
}


void RigidBody:: AddForce(const Vec2& force){
    // Math: a=F/m
    //we use multiplication with inverse_mass because it is much faster
    Vec2 resulting_acceleration = force*inverse_mass;

    //we add it to existing acceleration in case multiple forces act at once
    acceleration = acceleration + resulting_acceleration;
}

void RigidBody::Integrate(float dt){
    velocity = velocity + (acceleration* dt);

    position = position + (velocity * dt);

    //clear acc for next frame
    acceleration = Vec2(0.0f,0.0f);
}

