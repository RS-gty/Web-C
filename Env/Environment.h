//
// Created by ADMIN on 25-7-23.
//

#ifndef WEB_ENVIRONMENT_H
#define WEB_ENVIRONMENT_H

#include "../Algorithm/BinaryTree/BinaryTree.h"
#include "../Signal/Signal.h"
#include <Eigen/Dense>

using namespace Eigen;

class Environment {
public:
    Environment(double r, Vector3d o);
    Environment();

    void addSignal(Signal s){

    }

private:
    double radius{};
    Vector3d origin;
    BinaryTree Signals = new BinaryNode();
};

class Universe : public Environment{
public:
    Universe();
};


#endif//WEB_ENVIRONMENT_H
