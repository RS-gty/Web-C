//
// Created by ADMIN on 25-7-23.
//

#include "Environment.h"
#include <Eigen/Dense>
#include <utility>


Environment::Environment() {
    atomic<bool> running(true);
};

void Environment::AppendSignal(string signal) {
    AppendBinaryTree(this->signal_storage, std::move(signal));
}

void Environment::ScanSignals() {
    PreOrderTraverse(this->signal_storage);
}

void Environment::Update() {
    cout << "10" << endl;
}


