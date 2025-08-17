//
// Created by ADMIN on 25-7-23.
//

#ifndef WEB_SERVER_H
#define WEB_SERVER_H

#include "../Env/Environment.h"
#include "../Signal/Signal.h"
#include "../utils/utils.h"
#include <Eigen/Dense>
#include <string>
#include <vector>

using namespace std;
using namespace Eigen;

// Main Class
class Server {
public:
    Server(Environment &env, Vector3d pos);
    Server(Environment &env, double x, double y, double z);
    string get_id();
    void SetSignal(double amp, double fre, double phi);
    void RandomlizeID();

private:
protected:
    Signal signal;
    Environment *env;
    Vector3d position;
    string identifier;
};

//

class SubServer : public Server {
public:
private:
};

//

class Host : public Server {
public:
    Host(Environment &env, Vector3d pos);
    Host(Environment &env, double x, double y, double z);

    void RegisterServer();

private:
};


#endif// WEB_SERVER_H
