#include <iostream>
#include <iomanip> // Used to format the terminal output nicely
#include "RigidBody.h"

int main() {
    // Create a 10kg ball suspended at Y = 100
    RigidBody myBall(0.0f, 10.0f, 10.0f);
    float radius = 5.0f;

    // The World Rules
    Vec2 gravityForce(0.0f, -98.1f);
    float dt = 1.0f / 60.0f; // 60 FPS
    
    float floor_y = 0.0f;
    float restitution = 0.7f; // Retains 70% of its velocity on a bounce

    std::cout << "Starting Bouncing Simulation..." << std::endl;

    // Simulate 60 frames (1 full second of gameplay)
    for (int frame = 1; frame <= 120; frame++) {
        
        // 1. Add Gravity
        myBall.AddForce(gravityForce);

        // 2. Step Time Forward
        myBall.Integrate(dt);

        // 3. COLLISION DETECTION & RESOLUTION
        if (myBall.position.y - radius <= floor_y) {
            
            // A. Positional Correction (Snap it to the surface)
            myBall.position.y = floor_y + radius;
            
            // B. Impulse Resolution (Bounce and lose energy)
            myBall.velocity.y = -myBall.velocity.y * restitution;
            
            std::cout << "--- BOUNCE DETECTED ON FRAME " << frame << " ---" << std::endl;
        }

        // 4. Render the output (Only print every 5 frames to avoid terminal spam)
        if (frame % 5 == 0) {
            std::cout << "Frame " << std::setw(2) << frame << " | "
                      << "Velocity Y: " << std::setw(8) << myBall.velocity.y << " | "
                      << "Position Y: " << std::setw(8) << myBall.position.y << std::endl;
        }
    }

    return 0;
}