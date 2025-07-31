//
// Created by ADMIN on 25-7-23.
//

#include "Signal.h"
#include <Eigen/Dense>
#include <iostream>
#include <utility>

using namespace Eigen;


Signal::Signal(double amp, double fre, double phi) {
    amplitude = amp;
    frequency = fre;
    phase = phi;
}

void Signal::set_origin(Vector3d pos) {
    position = std::move(pos);
}

void Signal::set_origin(double x, double y, double z) {
    position = Vector3d(x, y, z);
}
void Signal::fade() {
    std::cout << "fade" << std::endl;
    delete this;
}

Eigen::Vector3d Signal::get_origin() {
    return position;
}

Signal::~Signal() {
}
