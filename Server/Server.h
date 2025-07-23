//
// Created by ADMIN on 25-7-23.
//

#ifndef WEB_SERVER_H
#define WEB_SERVER_H

#include <Eigen/Dense>
#include <string>
#include <vector>
#include "../Env/Environment.h"

using namespace std;
using namespace Eigen;

class Server {
public:
    Server(Vector3d pos);
    Server(double x, double y, double z);

    string get_id();

private:


protected:
    Vector3d position;
    string identifier;
};

class Host : public Server {
public:
    Host(Vector3d pos, double er);

    void RegisterServer();
    bool isAccessible(const Vector3d &sp);


private:
    double env_radius;
    Environment env;


    struct subserver{
        string identifier;
    };
    vector<subserver> subServers;
};

class SubServer : public Server {
public:
private:
};

#endif// WEB_SERVER_H
