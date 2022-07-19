#include <SFML/Graphics.hpp>
#include "Particle.cpp"
#include <vector>
#include <cmath>
#include <iostream>

using namespace sf;
using namespace std;


void GenerateParticles(int num, Particle *arr);



int main() {
    RenderWindow window(VideoMode(1600, 1000), "Simple Orbital Simulation");
    GravitySource gravitySource(window.getSize().x / 2, window.getSize().y / 2, 10000);
    window.setFramerateLimit(60);

    Font font;
    font.loadFromFile("/Users/kavinsankar/CLionProjects/SimpleParticleSimulation/Montserrat-Bold.ttf");


    // Generate Particles
    const int NumberOfParticles = 20000;
    Particle arr[NumberOfParticles];
    GenerateParticles(NumberOfParticles, arr);

    float FPS;
    sf::Clock clock;
    sf::Time previousTime = clock.getElapsedTime();
    sf::Time currentTime;

    // Setting the text as the current FPS
    Text framerate("60", font, 30);
    framerate.setPosition(1435.f, 0.f);

    // Drawing the FPS symbol on the window
    Text fps_text("FPS:", font, 30);
    fps_text.setPosition(1360.f, 0.f);


    while (window.isOpen()) {
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed)
                window.close();
        }

        window.clear();


        for (Particle &i: arr) // update particles' movements
            i.UpdatePhysics(gravitySource);

        gravitySource.Render(window); // draw the gravity source

        for (Particle &i: arr) // draw the particles
            i.Render(window);



        // Calculate FPS of program
        currentTime = clock.getElapsedTime();
        FPS = 1.0f / (currentTime.asSeconds() - previousTime.asSeconds()); // the asSeconds returns a float
        string fps_toString = to_string(FPS);
        previousTime = currentTime;


        // Setting the text as the current FPS
        framerate.setString(fps_toString);


        window.draw(framerate);
        window.draw(fps_text);

        window.display();
    }
}

void GenerateParticles(int size, Particle *arr) {
    srand(time(NULL));
    for (int i = 0; i < size; ++i) {

        // Uniform Elliptical Orbit
        float posX = rand() % 100;
        float posY = rand() % 100;
        float velX = 1.f + rand() % 5;

        int R = 128 + (rand() % 255);
        int G = 10 + rand() % 160;
        int B = 50 + rand() % 122;

        Color c{static_cast<Uint8>(R), static_cast<Uint8>(G), static_cast<Uint8>(B)};

        arr[i] = Particle(posX, posY, velX, 0, c);
    }
}

void GeneratePoints(int size, Vertex *vArr) {
    for (int i = 0; i < size; ++i) {
        float posX = 100;
        float posY = 10;

        Vertex point(sf::Vector2f(posX, posY), sf::Color::Yellow);
        vArr[i] = point;
    }
}