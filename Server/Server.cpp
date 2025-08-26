//
// Created by ADMIN on 25-7-23.
//

#include "Server.h"

using namespace std;
using namespace Eigen;

Server::Server(Vector3d pos) {
    this->storage_maxlength = 1024;

    identifier = RandomUUID();

    position = std::move(pos);

    position_ptr = &position;
    // signal init
    auto *s = new Signal(0, 0, 0, this->identifier);
    signal = s;
    signal->set_origin(this->position_ptr);
    signal->set_starttime(*this->time);

    // listener init

    auto *lis = new Listener(this->position, this->amplitude_storage, 1024);
    listener = lis;
}


Server::Server(double x, double y, double z){
    this->storage_maxlength = 1024;

    identifier = RandomUUID();

    position = Vector3d(x, y, z);

    position_ptr = &position;

    auto *s = new Signal(0, 0, 0, this->identifier);
    signal = s;
    signal->set_origin(this->position_ptr);
    signal->set_starttime(*this->time);

    // listener init

    auto *lis = new Listener(this->position, this->amplitude_storage, 1024);
    listener = lis;
}

void Server::RandomlizeID() {
    this->identifier = RandomUUID();
}

void Server::SetSignal(double amp, double fre, double phi) {
    this->signal->set_properties(amp, fre, phi);
}

void Server::BindPosition(Particle &particle) {
    this->position_ptr = particle.position_ptr;
    this->signal->set_origin(this->position_ptr);
    this->listener->setPosition(this->position_ptr);
}

void Server::StorageInit(int max_length) {
    this->storage_maxlength = max_length;
}

void Server::passIntensity(double i) {
    this->listener->Listen(i);
}

void Server::setTime(long double *t) {
    this->time = t;
}

Vector3d &Server::getPosition() {
    return *this->position_ptr;
}

string Server::get_id() {
    return identifier;
}
