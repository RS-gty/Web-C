//
// Created by ADMIN on 25-7-23.
//

#ifndef WEB_SIGNAL_H
#define WEB_SIGNAL_H

#include <Eigen/Dense>

using namespace Eigen;

typedef long long int lint;

class Signal {
public:
    Signal(double amp, double fre, double phi);
    ~Signal();
    void set_origin(Vector3d pos);
    void set_origin(double x, double y, double z);
    void fade();
    Vector3d get_origin();

private:
protected:
    double amplitude;
    double frequency;
    double phase;
    lint start_frame;
    lint duration;
    Vector3d position;
};


#endif//WEB_SIGNAL_H
