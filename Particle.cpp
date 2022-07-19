#include <SFML/Graphics.hpp>
#include <cmath>

#include "GravitySource.cpp"

class Particle {
public:
    sf::Vector2f pos;
    sf::Vector2f velocity;
    sf::CircleShape particle;
    sf::Color color;

public:
    Particle() {}

    Particle(float posX, float posY, float velX, float velY, sf::Color color) {
        pos.x = posX;
        pos.y = posY;

        velocity.x = velX;
        velocity.y = velY;
        this->color = color;

        particle.setPosition(pos);
        particle.setRadius(1.5f);
        particle.setFillColor(color);
    }

    void Render(sf::RenderWindow &window) {
        particle.setPosition(pos);
        window.draw(particle);
    }

    void UpdatePhysics(GravitySource source) {
        float distanceX = source.GetPosition().x - pos.x;
        float distanceY = source.GetPosition().y - pos.y;

        float distance = sqrt(distanceX * distanceX + distanceY * distanceY);
        float inverseDistance = 1.f / distance;

        float normX = distanceX * inverseDistance;
        float normY = distanceY * inverseDistance;

        float invSquareDropOff = inverseDistance * inverseDistance;

        float accX = normX * source.GetStrength() * invSquareDropOff;
        float accY = normY * source.GetStrength() * invSquareDropOff;

        velocity.x += accX;
        velocity.y += accY;

        pos.x += velocity.x;
        pos.y += velocity.y;
    }
};