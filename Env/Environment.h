//
// Created by ADMIN on 25-7-23.
//

#ifndef WEB_ENVIRONMENT_H
#define WEB_ENVIRONMENT_H

#include <Eigen/Dense>

using namespace Eigen;

class Environment {
public:
    Environment(double r, Vector3d o);
    Environment();

private:
    double radius{};
    Vector3d origin;
};


#endif//WEB_ENVIRONMENT_H
