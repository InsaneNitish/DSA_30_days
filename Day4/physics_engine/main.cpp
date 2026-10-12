#include <SFML/Graphics.hpp>
#include "RigidBody.h"
#include <vector>
#include <random>

// Your exact collision math (Unchanged!)
void ResolveCollision(RigidBody &A, RigidBody &B, float restitution)
{
    Vec2 normal = B.position - A.position;
    float distance = normal.Length();
    if (distance == 0.0f)
        return;

    normal = normal.Normalize();
    Vec2 relative_velocity = B.velocity - A.velocity;
    float velocity_along_normal = relative_velocity.Dot(normal);

    if (velocity_along_normal > 0.0f)
        return;

    float j = -(1.0f + restitution) * velocity_along_normal;
    j = j / (A.inverse_mass + B.inverse_mass);

    Vec2 impulse = normal * j;
    A.velocity = A.velocity - (impulse * A.inverse_mass);
    B.velocity = B.velocity + (impulse * B.inverse_mass);
}

int main()
{

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<float> distribX(50.0f, 600.0f);
    std::uniform_real_distribution<float> distribY(50.0f, 600.0f);
    std::uniform_real_distribution<float> distribMass(5.0f, 15.0f);

    //color array
    // --- NEW COLOR SETUP ---
    // 1. Create a palette of colors
    std::vector<sf::Color> palette = {
        sf::Color::Red, sf::Color::Green, sf::Color::Blue,
        sf::Color::Yellow, sf::Color::Magenta, sf::Color::Cyan,
        sf::Color::White
    };
    
    // 2. Create an RNG that picks a whole number between 0 and the end of the palette
    std::uniform_int_distribution<int> distribColor(0, palette.size() - 1);
    
    // 3. The Parallel Array (This holds the color for each ball on the screen)
    std::vector<sf::Color> bodyColors;
    // 1. OPEN THE WINDOW (Updated for SFML 3 strict Vectors)
    const unsigned int WINDOW_WIDTH = 1200;
    const unsigned int WINDOW_HEIGHT = 600;
    sf::RenderWindow window(sf::VideoMode(sf::Vector2u(WINDOW_WIDTH, WINDOW_HEIGHT)), "C++ Physics Engine");
    window.setFramerateLimit(60);

    // 2. SETUP THE PHYSICS OBJECTS
    float radius = 10.0f;
    float floor_y = 50.0f;

    std::vector<RigidBody> bodies;

// Drop Ball A
    bodies.push_back(RigidBody(200.0f, 500.0f, 10.0f));
    bodyColors.push_back(palette[distribColor(gen)]); // Give it a random color!

    // Drop Ball B
    bodies.push_back(RigidBody(220.0f, 100.0f, 10.0f));
    bodies[1].velocity = Vec2(0.0f, 400.0f);
    bodyColors.push_back(palette[distribColor(gen)]); // Give it a random color!

    Vec2 gravity(0.0f, -981.0f);
    Vec2 wind(200.0f, 4.0f);
    Vec2 airDrag(0.0, 50.0f);
    float dt = 1.0f / 60.0f;
    float bounciness = 0.9f;

    // 3. SETUP THE GRAPHICS OBJECT
    sf::CircleShape circleShape(radius);
    circleShape.setFillColor(sf::Color::Cyan);
    // Updated for SFML 3
    circleShape.setOrigin(sf::Vector2f(radius, radius));

    // 4. THE MASTER RENDER LOOP
    while (window.isOpen())
    {

        // --- A. HANDLE OS EVENTS (Updated for SFML 3 std::optional) ---
        while (const std::optional<sf::Event> event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
            {
                window.close();
            }
        }

        // --- B. PHYSICS UPDATE ---
        for (int i = 0; i < bodies.size(); i++)
        {
            bodies[i].AddForce(gravity);
            bodies[i].AddForce(wind);
            bodies[i].AddForce(airDrag);
            bodies[i].Integrate(dt);

            // 1. Floor (Bottom of the math world, Y = 0)
            if (bodies[i].position.y - radius <= 50.0f)
            {
                bodies[i].position.y = radius + 50.0f;                     // Push it back out so it doesn't sink
                bodies[i].velocity.y = -bodies[i].velocity.y * bounciness; // Flip Y
            }
            // 2. Ceiling (Top of the math world, Y = WINDOW_HEIGHT)
            else if (bodies[i].position.y + radius >= WINDOW_HEIGHT)
            {
                bodies[i].position.y = WINDOW_HEIGHT - radius;
                bodies[i].velocity.y = -bodies[i].velocity.y * bounciness; // Flip Y
            }

            // 3. Left Wall (X = 0)
            if (bodies[i].position.x - radius <= 0.0f)
            {
                bodies[i].position.x = radius;
                bodies[i].velocity.x = -bodies[i].velocity.x * bounciness; // Flip X
            }
            // 4. Right Wall (X = WINDOW_WIDTH)
            else if (bodies[i].position.x + radius >= WINDOW_WIDTH)
            {
                bodies[i].position.x = WINDOW_WIDTH - radius;
                bodies[i].velocity.x = -bodies[i].velocity.x * bounciness; // Flip X
            }
        }

        // Circle-vs-Circle Collision Detection
        for (int i = 0; i < bodies.size(); i++)
        {
            for (int j = i + 1; j < bodies.size(); j++)
            {
                Vec2 distVec = bodies[j].position - bodies[i].position;
                if (distVec.Length() <= (radius * 2))
                {
                    ResolveCollision(bodies[i], bodies[j], bounciness);
                    float overlap = (radius * 2) - distVec.Length();
                    Vec2 correction = distVec.Normalize() * (overlap / 2.0f);
                    bodies[i].position = bodies[i].position - correction;
                    bodies[j].position = bodies[j].position + correction;

                    if (bodies.size() <= 1500)
                    {
                        bodies.push_back(RigidBody(distribX(gen), distribY(gen), distribMass(gen)));
                        bodyColors.push_back(palette[distribColor(gen)]);
                    }
                }
            }
        }

        // --- C. RENDER PIPELINE ---

        window.clear(sf::Color::Black);

        for (int i = 0; i < bodies.size(); i++)
        {
            float screen_x = bodies[i].position.x;
            float screen_y = WINDOW_HEIGHT - bodies[i].position.y;

            // Updated for SFML 3
            circleShape.setPosition(sf::Vector2f(screen_x, screen_y));
            // --- NEW: Change the paintbrush color for this specific ball ---
            circleShape.setFillColor(bodyColors[i]);
            window.draw(circleShape);
        }

        sf::RectangleShape floorShape(sf::Vector2f(WINDOW_WIDTH, 5.0f));
        floorShape.setFillColor(sf::Color::White);
        // Updated for SFML 3
        floorShape.setPosition(sf::Vector2f(0.0f, WINDOW_HEIGHT - floor_y));
        window.draw(floorShape);

        window.display();
    }

    return 0;
}