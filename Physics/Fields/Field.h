//
// Created by RSgty on 25-8-17.
//

#ifndef FIELD_H
#define FIELD_H

#include <iostream>
#include <Eigen/Dense>

#include "../../utils/utils.h"
#include "../../Algorithm/BinaryTree/BinaryTree.h"
#include "../Objects/Particle.h"

using namespace Eigen;

class Field {
public:
    Field() {type = 0;};

    double strength;
    Vector3d direction;
    virtual Vector3d getForce(Particle particle)  {return {0, 0, 0};};

    int type;

private:
};

class ConstGravityField : public Field {
    public:
    ConstGravityField(double strength, Vector3d direction);

    Vector3d getForce(Particle particle) override{
        return this->direction * this->strength * particle.mass;
    }
};

class MagneticField : public Field {
    public:
    MagneticField(double strength, Vector3d direction);

    Vector3d getForce(Particle particle) override{
        return this->strength * particle.charge * particle.velocity.cross(this->direction);
    }
};

class GravityField : public Field {
    public:
    GravityField(double mass, Vector3d position);

    Vector3d getForce(Particle particle) override{
        Vector3d dir_force = this->direction - particle.position;
        double distance_squared = pow(dir_force.norm(), 2);
        dir_force.normalize();
        return (particle.mass * this->strength / distance_squared) * dir_force;
    }
};





#endif //FIELD_H
