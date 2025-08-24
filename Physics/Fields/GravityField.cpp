//
// Created by RSgty on 25-8-18.
//

#include "Field.h"

GravityField::GravityField(double mass, Vector3d position) : Field() {
    this->strength = mass;
    this->direction = move(position);
    this->type = 3;
}
