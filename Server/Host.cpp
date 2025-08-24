//
// Created by ADMIN on 25-7-23.
//
#include "../Env/Environment.h"
#include "Server.h"
#include <string>

#include <utility>

void Host::RegisterServer() {
}

Host::Host(Environment &env, Vector3d pos) : Server(env, std::move(pos)) {
}

Host::Host(Environment &env, double x, double y, double z) : Server(env, x, y, z) {
}
