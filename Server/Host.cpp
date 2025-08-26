//
// Created by ADMIN on 25-7-23.
//
#include "Server.h"
#include <string>

#include <utility>

void Host::RegisterServer() {
}

Host::Host(Vector3d pos) : Server(std::move(pos)) {
}

Host::Host(double x, double y, double z) : Server(x, y, z) {
}
