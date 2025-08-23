//
// Created by ADMIN on 25-7-23.
//

#include "Environment.h"
#include <Eigen/Dense>
#include <utility>


Environment::Environment(long long int &iter, long double &time_counter) {
    atomic<bool> running(true);
    this->iter = &iter;
    this->time_counter = &time_counter;
};

long double Environment::getTime() {
    return *this->time_counter;
}

double Environment::getSignalIntensity(Vector3d &position) {
    double signalIntensity = 0;
    for (auto i : this->signals) {
        signalIntensity += i.getIntensity(*this->time_counter, position);
    }
    return signalIntensity;
}


void Environment::AppendSignal(Signal &signal) {
    this->signals.push_back(signal);
}


void Environment::Update() {
    cout << "10" << endl;
}


