/*
#include <SFML/Graphics.hpp>
#include "Particle.cpp"
#include <vector>
#include <cmath>
#include <iostream>

using namespace sf;
using namespace std;


// ----------------Function Declarations---------------- //
void GeneratePoints(int size, Vertex *vArr);

void UpdatePoints(GravitySource &source, Vertex *vArr);

void InitVelocities(int size, float *velArr);
// ----------------Function Declarations---------------- //


int main() {
    RenderWindow window(VideoMode(1600, 1000), "Simple Orbital Simulation");
    GravitySource gravitySource(window.getSize().x / 2, window.getSize().y / 2, 3000);
    window.setFramerateLimit(60);

    Font font;
    font.loadFromFile("/Users/kavinsankar/CLionProjects/SimpleParticleSimulation/Montserrat-Bold.ttf");


    // Generate Points (or pixels)
    const int NumberOfPoints = 200000;
    Vertex points_arr[NumberOfPoints];
    GeneratePoints(NumberOfPoints, points_arr);
//    const int NumberOfPoints = 50000;
//    Vertex points_arr[NumberOfPoints];
//    Vertex points_arr2[NumberOfPoints];
//    Vertex points_arr3[NumberOfPoints];
//    Vertex points_arr4[NumberOfPoints];
//    GeneratePoints(NumberOfPoints, points_arr);
//    GeneratePoints(NumberOfPoints, points_arr2);
//    GeneratePoints(NumberOfPoints, points_arr3);
//    GeneratePoints(NumberOfPoints, points_arr4);


    // Initialize velocities
    float velocitiesX[NumberOfPoints];
    float velocitiesY[NumberOfPoints];
    InitVelocities(NumberOfPoints, velocitiesX);
    InitVelocities(NumberOfPoints, velocitiesY);


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



//    Vertex point(sf::Vector2f(500, 500), sf::Color::Yellow);
//    Vertex test[1];
//    test[0] = point;


    while (window.isOpen()) {
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed)
                window.close();
        }

        window.clear();



//        for (Vertex point: points_arr) {
//            UpdatePoints(gravitySource, &point);
//        }
        for (int i = 0; i < NumberOfPoints; ++i) {
            float distanceX = gravitySource.GetPosition().x - points_arr[i].position.x;
            float distanceY = gravitySource.GetPosition().y - points_arr[i].position.y;

            float distance = sqrt(distanceX * distanceX + distanceY * distanceY);
            float inverseDistance = 1.f / distance;

            float normX = distanceX * inverseDistance;
            float normY = distanceY * inverseDistance;

            float invSquareDropOff = inverseDistance * inverseDistance;

            float accX = normX * gravitySource.GetStrength() * invSquareDropOff;
            float accY = normY * gravitySource.GetStrength() * invSquareDropOff;

            velocitiesX[i] += accX;
            velocitiesY[i] += accY;
            sf::Vector2f vel(velocitiesX[i], velocitiesY[i]);

            points_arr[i].position += vel;

            points_arr[i].position.x += velocitiesX[i];
            points_arr[i].position.y += velocitiesY[i];

//            points_arr2[i].position.x += velocitiesX[i];
//            points_arr2[i].position.y += velocitiesY[i];
//
//            points_arr3[i].position.x += velocitiesX[i];
//            points_arr3[i].position.y += velocitiesY[i];
//
//            points_arr4[i].position.x += velocitiesX[i];
//            points_arr4[i].position.y += velocitiesY[i];
        }

        gravitySource.Render(window); // draw the gravity source

        for (Vertex point: points_arr) {
            window.draw(&point, 1, Points);
        }


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

void UpdatePoints(GravitySource &source, Vertex *point) {
    float distanceX = source.GetPosition().x - point->position.x;
    float distanceY = source.GetPosition().y - point->position.y;

    float distance = sqrt(distanceX * distanceX + distanceY * distanceY);
    float inverseDistance = 1.f / distance;

    float normX = distanceX * inverseDistance;
    float normY = distanceY * inverseDistance;

    float invSquareDropOff = inverseDistance * inverseDistance;

    float accX = normX * source.strength * invSquareDropOff;
    float accY = normY * source.strength * invSquareDropOff;


    //float velX = vel + accX;
    //float velY = vel + accY;

    //point->texCoords.x += velX;
    //point->texCoords.y += velY;

    //point->position.x += velX;
    //point->position.y += velY;
}

void GeneratePoints(int size, Vertex *vArr) {
    for (int i = 0; i < size; ++i) {
        float posX = rand() % 1600;
        float posY = rand() % 1000;

        int R = (rand() % 255);
        int G = rand() % 255;
        int B = rand() % 255;

        Color c{static_cast<Uint8>(R), static_cast<Uint8>(G), static_cast<Uint8>(B)};

        Vertex point(sf::Vector2f(posX, posY), sf::Color::Yellow);
        vArr[i] = point;
    }
}

void InitVelocities(int size, float *velArr) {
    for (int i = 0; i < size; ++i) {
        velArr[i] = 0;
    }
}
*/
