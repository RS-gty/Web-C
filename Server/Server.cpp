//
// Created by ADMIN on 25-7-23.
//

#include "Server.h"

using namespace std;
using namespace Eigen;

Server::Server(Environment &env, Vector3d pos) {
    this->env = &env;

    identifier = RandomUUID();

    auto *s = new Signal(env, 0, 0, 0, this->identifier);
    signal = *s;
    env.AppendSignal(signal);

    position = std::move(pos);

    position_ptr = &position;
}


Server::Server(Environment &env, double x, double y, double z) {
    this->env = &env;

    identifier = RandomUUID();

    auto *s = new Signal(env, 0, 0, 0, this->identifier);
    signal = *s;
    env.AppendSignal(signal);

    position = Vector3d(x, y, z);

    position_ptr = &position;
}

void Server::RandomlizeID() {
    this->identifier = RandomUUID();
}

void Server::SetSignal(double amp, double fre, double phi) {
    this->signal.set_properties(amp, fre, phi);
}

void Server::BindPosition(Particle &particle) {
    this->position_ptr = particle.position_ptr;
}

Vector3d Server::getPosition() {
    return *this->position_ptr;
}

string Server::get_id() {
    return identifier;
}
