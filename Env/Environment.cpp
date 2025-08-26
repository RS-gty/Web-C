//
// Created by ADMIN on 25-7-23.
//

#include "Environment.h"
#include <Eigen/Dense>
#include <utility>


Environment::Environment(double delta) {
    this->delta = delta;
};

Environment::Environment(Environment &extend, double delta) {
    this->delta = delta;

    this->fields = extend.fields;
    this->particles = extend.particles;
    this->signals = extend.signals;
    this->time_counter = extend.time_counter;
    this->iter = extend.iter;
}


long double Environment::getTime() {
    return this->time_counter;
}

double Environment::getSignalIntensity(Vector3d &position) {
    double signalIntensity = 0;
    for (auto i: this->signals) {
        signalIntensity += i->getIntensity(this->time_counter, position);
    }
    return signalIntensity;
}

double Environment::getSignalIntensity(double x, double y, double z) {
    double signalIntensity = 0;
    Vector3d v = Vector3d(x, y, z);
    for (auto i: this->signals) {
        signalIntensity += i->getIntensity(this->time_counter, v);
    }
    return signalIntensity;
}


void Environment::AppendSignal(Signal *signal) {
    this->signals.push_back(signal);
}

void Environment::AppendServer(Server *server) {
    server->setTime(&this->time_counter);
    server->signal->set_starttime(this->time_counter);
    this->servers.push_back(server);
    this->AppendSignal(server->signal);

}


void Environment::appendField(Field *field) {
    this->fields.push_back(field);
}

void Environment::appendField(const vector<Field *> &fields) {
    for (auto &field: fields) {
        this->fields.push_back(field);
    }
}


void Environment::appendParticle(Particle &particle) {
    this->particles.push_back(&particle);
}

void Environment::appendParticle(const vector<Particle *> &particles) {
    for (auto &particle: particles) {
        this->particles.push_back(particle);
    }
}

void Environment::Update() {
    // position update
    for (auto &particle: particles) {
        particle->acceleration = Vector3d::Zero();
        for (auto *f_iter: fields) {
            particle->acceleration += f_iter->getForce(*particle) / particle->mass;
        }
        particle->velocity += particle->acceleration * delta;
        particle->position += particle->velocity * delta;
    }
    // signal receive
    for (auto &server : servers) {
        cout << this->getSignalIntensity(1, 2, 3) << endl;
        server->passIntensity(this->getSignalIntensity(server->getPosition()));
    }
    this->iter ++;
    this->time_counter += delta;
}

long long int Environment::getIteration() {
    return this->iter;
}

