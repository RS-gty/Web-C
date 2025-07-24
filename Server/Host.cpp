//
// Created by ADMIN on 25-7-23.
//
#include "../Env/Environment.h"
#include "Server.h"
#include <string>

#include <utility>

void Host::RegisterServer() {
}

bool Host::isAccessible(const Vector3d &sp) {
    return ((sp - position).norm() < env_radius);
}

Host::Host(Vector3d pos, double er) : Server(std::move(pos)) {
    env_radius = er;
    env = Environment(er, position);
}
Host::Host(double x, double y, double z, double er) : Server(x, y, z) {
    env_radius = er;
    env = Environment(er, position);
}
