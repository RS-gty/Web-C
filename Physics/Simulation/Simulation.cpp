//
// Created by RSgty on 25-8-17.
//

#include "Simulation.h"

void Simulation::appendField(Field* field) {
    this->fields.push_back(field);
}
void Simulation::appendField(vector<Field*> fields) {
    for (auto iter = fields.begin(); iter != fields.end(); iter++) {
        this->fields.push_back(*iter);
    }
}


void Simulation::appendParticle(Particle &particle) {
    this->particles.push_back(&particle);
}
void Simulation::appendParticle(vector<Particle*> particles) {
    for (auto iter = particles.begin(); iter != particles.end(); iter++) {
        this->particles.push_back(*iter);
    }
}

void Simulation::simulate_begin(bool &running, double delta) {
    int iter = 0;
    while (running) {
        for (auto p_iter = particles.begin(); p_iter != particles.end(); p_iter++) {
            (*p_iter)->acceleration = Vector3d::Zero();
            for (auto* f_iter : fields) {
                (*p_iter)->acceleration += f_iter->getForce(**p_iter);
            }
            (*p_iter)->velocity += (*p_iter)->acceleration * delta;
            (*p_iter)->position += (*p_iter)->velocity * delta;
        }
        iter++;
        if (iter == 1000){running = false;}
    }
}