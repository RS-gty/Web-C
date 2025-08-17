//
// Created by RSgty on 25-8-17.
//

#ifndef SIMULATION_H
#define SIMULATION_H

#include <iostream>
#include <vector>
#include "../Objects/Particle.h"
#include "../Fields/Field.h"

using namespace std;

class Simulation {
public:
    Simulation() = default;

    vector<Particle*> particles;
    vector<Field*> fields;

    void appendField(Field *field);
    void appendField(vector<Field*> fields);

    void appendParticle(Particle &particle);
    void appendParticle(vector<Particle*> particles);


    void simulate_begin(bool &running, double delta);
};



#endif //SIMULATION_H
