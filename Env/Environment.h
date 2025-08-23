//
// Created by ADMIN on 25-7-23.
//

#ifndef WEB_ENVIRONMENT_H
#define WEB_ENVIRONMENT_H

#include "../Algorithm/BinaryTree/BinaryTree.h"
#include "../Signal/Signal.h"
#include <Eigen/Dense>
#include <string>
#include <iostream>
#include <queue>

using namespace Eigen;
using namespace std;

class Environment {
public:
    explicit Environment(long long int &iter, long double &time_counter);
    void AppendSignal(Signal &signal);
    long double getTime();

    double getSignalIntensity(Vector3d &position);

    long long int *iter;
    long double *time_counter;

    void Update();
private:
    vector<Signal> signals = {};

};


#endif//WEB_ENVIRONMENT_H
