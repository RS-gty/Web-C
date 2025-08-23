//
// Created by ADMIN on 25-7-23.
//

#include "Signal.h"

#include <utility>

using namespace Eigen;


Signal::Signal(double amp, double fre, double phi, string id) {
    amplitude = amp;
    frequency = fre;
    phase = phi;
    identifier = move(id);
}

void Signal::set_origin(Vector3d *pos) {
    position = pos;
}

void Signal::set_properties(double amp, double fre, double phi) {
    this->amplitude = amp;
    this->frequency = fre;
    this->phase = phi;
}

void Signal::set_starttime(long double st) {
    this->start_time = st;
}

double Signal::getIntensity(long double current_time, Vector3d pos) {
    double distance = (pos - *this->position).norm();
    double delta_distance = current_time - this->start_time;
    if (distance <= delta_distance) {
        // this->wavelength equals 1 / this->frequency
        double ext = delta_distance - distance;
        return this->amplitude * sin(2 * numbers::pi * ext * this->frequency + this->phase);
    } else {return 0;}
}


void Signal::fade() {
    std::cout << "fade" << std::endl;
    delete this;
}

Vector3d* Signal::get_origin() {
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
