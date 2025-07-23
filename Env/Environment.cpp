//
// Created by ADMIN on 25-7-23.
//

#include "Environment.h"
#include <Eigen/Dense>
#include <utility>


Environment::Environment(double r, Vector3d o) {
    radius = r;
    origin = std::move(o);
}
Environment::Environment() {
    radius = 0;
    origin = Vector3d (0, 0, 0);
}
