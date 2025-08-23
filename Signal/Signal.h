//
// Created by ADMIN on 25-7-23.
//
#ifndef WEB_SIGNAL_H
#define WEB_SIGNAL_H

#include <iostream>
#include <Eigen/Dense>
#include <boost/uuid/uuid_generators.hpp>
#include <boost/uuid/uuid_io.hpp>
#include "../utils/utils.h"

using namespace Eigen;

typedef long long int lint;

class Signal {
public:
    Signal();

    Signal(double amp, double fre, double phi, string id);

    ~Signal();

    void passID(string id);
    void set_origin(Vector3d *pos);
    void set_origin(double x, double y, double z);
    void set_properties(double amp, double fre, double phi);
    void set_starttime(long double st);

    double getIntensity(long double current_time, Vector3d pos);

    void fade();
    Vector3d* get_origin();
    Signal *get_pointer();
    operator string() const;
    string identifier;

private:
protected:
    double amplitude{};
    double frequency{};
    double phase{};
    lint start_frame{};
    long double start_time{};
    lint duration{};
    Vector3d *position;
};


#endif//WEB_SIGNAL_H
