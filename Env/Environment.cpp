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


void Environment::AppendSignal(string signal) {
    AppendBinaryTree(this->signal_storage, std::move(signal));
}

void Environment::ScanSignals() {
    PreOrderTraverse(this->signal_storage);
}

void Environment::Update() {
    cout << "10" << endl;
}


