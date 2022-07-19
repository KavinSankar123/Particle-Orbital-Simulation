#include <SFML/Graphics.hpp>

class GravitySource {
public:
    sf::CircleShape source;
    sf::Vector2f pos;
    float strength;

public:
    GravitySource(float posX, float posY, float strength) {
        pos.x = posX;
        pos.y = posY;
        this->strength = strength;
        source.setPosition(pos);
        source.setFillColor(sf::Color::White);
        source.setRadius(10);

        //visible.setRadius(20);
        //visible.setFillColor(Color::Cyan);
    }

    void Render(sf::RenderWindow &window) {
        window.draw(source);
        //window.draw(visible);
    }


    sf::Vector2f GetPosition() {
        return pos;
    }

    float GetStrength() {
        return strength;
    }
};
