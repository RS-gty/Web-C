//
// Created by RSgty on 25-8-17.
//

#include "Particle.h"

Particle::Particle(double mass, Vector3d position, Vector3d velocity, double charge) {
    this->mass = mass;
    this->position = move(position);
    this->velocity = move(velocity);
    this->charge = charge;
}
