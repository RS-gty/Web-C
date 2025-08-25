//
// Created by ADMIN on 25-7-23.
//

#ifndef WEB_ENVIRONMENT_H
#define WEB_ENVIRONMENT_H

#include "../Algorithm/BinaryTree/BinaryTree.h"
#include "../Signal/Signal.h"
#include "../Physics/Objects/Particle.h"
#include "../Physics/Fields/Field.h"
#include <vector>
#include <Eigen/Dense>
#include <string>
#include <iostream>
#include <queue>

using namespace Eigen;
using namespace std;

class Environment {
public:
    explicit Environment(double delta);
    Environment(Environment &extend, double delta);

    void AppendSignal(Signal &signal);

    long double getTime();

    double getSignalIntensity(Vector3d &position);

    double getSignalIntensity(double x, double y, double z);

    void appendField(Field *field);

    void appendField(const vector<Field *> &fields);

    void appendParticle(Particle &particle);

    void appendParticle(const vector<Particle *> &particles);

    void Update();

    long long int getIteration();

    vector<Particle *> particles;
    vector<Field *> fields;
    vector<Signal *> signals;
    double delta = static_cast<double>(1) / 1024;
    long long int iter = 0;
    long double time_counter = 0;

private:

};


#endif//WEB_ENVIRONMENT_H
