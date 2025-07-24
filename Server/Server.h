//
// Created by ADMIN on 25-7-23.
//

#ifndef WEB_SERVER_H
#define WEB_SERVER_H

#include "../Env/Environment.h"
#include <Eigen/Dense>
#include <string>
#include <vector>

using namespace std;
using namespace Eigen;

class Server {
public:
    explicit Server(Vector3d pos);
    Server(double x, double y, double z);
    string get_id();

private:
protected:
    Vector3d position;
    string identifier;
};

class SubServer : public Server {
public:
private:
};

class Host : public Server {
public:
    Host(Vector3d pos, double er);
    Host(double x, double y, double z, double er);
    void RegisterServer();
    bool isAccessible(const Vector3d &sp);

private:
    double env_radius;
    Environment env;

    vector<SubServer> subServers;
};


#endif// WEB_SERVER_H
