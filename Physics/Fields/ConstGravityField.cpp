//
// Created by RSgty on 25-8-17.
//

#include "Field.h"

ConstGravityField::ConstGravityField(double strength, Vector3d direction) : Field() {
    this->strength = strength;
    this->direction = direction.normalized();
    this->type = 1;
}
