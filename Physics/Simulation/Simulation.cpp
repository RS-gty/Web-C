//
// Created by RSgty on 25-8-17.
//

#include "Simulation.h"

Simulation::Simulation(double delta) {
    this->delta = delta;
}


void Simulation::appendField(Field *field) {
    this->fields.push_back(field);
}

void Simulation::appendField(const vector<Field *> &fields) {
    for (auto &field: fields) {
        this->fields.push_back(field);
    }
}


void Simulation::appendParticle(Particle &particle) {
    this->particles.push_back(&particle);
}

void Simulation::appendParticle(const vector<Particle *> &particles) {
    for (auto &particle: particles) {
        this->particles.push_back(particle);
    }
}

void Simulation::update() {
    for (auto &particle: particles) {
        particle->acceleration = Vector3d::Zero();
        for (auto *f_iter: fields) {
            particle->acceleration += f_iter->getForce(*particle) / particle->mass;
        }
        particle->velocity += particle->acceleration * delta;
        particle->position += particle->velocity * delta;
    }
    iteration++;
}
