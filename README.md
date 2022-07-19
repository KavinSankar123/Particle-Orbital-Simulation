# Particle-Orbital-Simulation

<img width="783" alt="Demo" src="https://user-images.githubusercontent.com/90232501/179839566-3b5db708-282e-438a-b2ac-4a192cf225f4.png">
![ParticleDemo](https://user-images.githubusercontent.com/90232501/179840802-3ed9606c-cb5c-47a7-91c5-b096ddb3ec46.gif)

------------------------------------------------------------------------------------------------------------------------------------------

## About
- Simulating over 10,000 particles and their orbits around a singular gravity source (the white circle).
- Mading using C++ and SFML
- Utilizes the inverse-square law to simulate the effects of gravity

## Purpose
- To familiarize myself with C++ and practice object-oriented programming
- To learn a new library (SFML)
- To apply physics concepts I learned in class to a personal project

## Future Improvements
- Each particle is represented as a single object in memory
  - This consumes a lot of memory and therefore cannot render as many particles
- Current maximum particles is 22,000
  - I plan to use SFML primitives instead of objects so I can increase the particle amount to at least 200,000
