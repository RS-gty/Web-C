//
// Created by RSgty on 25-8-17.
//

#ifndef PARTICLE_H
#define PARTICLE_H

#include <Eigen/Dense>

using namespace Eigen;
using namespace std;

class Particle {
public:
    Particle(double mass, Vector3d position, Vector3d velocity, double charge = 0.0);

    double mass;
    double charge;
    Vector3d position;
    Vector3d *position_ptr;
    Vector3d velocity;
    Vector3d acceleration;
};



#endif //PARTICLE_H
