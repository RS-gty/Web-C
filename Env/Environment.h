//
// Created by ADMIN on 25-7-23.
//

#ifndef WEB_ENVIRONMENT_H
#define WEB_ENVIRONMENT_H

#include "../Algorithm/BinaryTree/BinaryTree.h"
#include <Eigen/Dense>
#include <string>
#include <iostream>
#include <queue>

using namespace Eigen;
using namespace std;

class Environment {
public:
    explicit Environment(long long int &iter, long double &time_counter);
    void AppendSignal(string signal);
    void ScanSignals();
    long double getTime();

    long long int *iter;
    long double *time_counter;

    void Update();
private:
    BinaryTree signal_storage = new BinaryNode();

};


#endif//WEB_ENVIRONMENT_H
