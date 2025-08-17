//
// Created by ADMIN on 25-7-23.
//

#include "Signal.h"

#include <utility>

using namespace Eigen;


Signal::Signal(Environment &env, double amp, double fre, double phi, string id) {
    exenv = env;
    amplitude = amp;
    frequency = fre;
    phase = phi;
    start_frame = exenv.frame;
    identifier = move(id);
}



void Signal::set_origin(Vector3d pos) {
    position = std::move(pos);
}

void Signal::set_origin(double x, double y, double z) {
    position = Vector3d(x, y, z);
}
void Signal::set_properties(double amp, double fre, double phi) {
    this->amplitude = amp;
    this->frequency = fre;
    this->phase = phi;
}
void Signal::fade() {
    std::cout << "fade" << std::endl;
    delete this;
}

Eigen::Vector3d Signal::get_origin() {
    return position;
}
Signal *Signal::get_pointer() {
    return this;
}
Signal::operator string() const {
    stringstream ss;
    ss << this;
    return identifier + ss.str();
}



Signal::~Signal() {
}
