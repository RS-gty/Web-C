//
// Created by RSgty on 25-8-26.
//

#include "Listener.h"

Listener::Listener(Vector3d &position, vector<double> &amplitude_storage, int storage_maxlength) {
    this->position = &position;
    this->amplitude_storage = &amplitude_storage;
    this->storage_maxlength = storage_maxlength;
}

void Listener::setPosition(Vector3d *pos) {
    this->position = pos;
}


void Listener::Listen(double i) {
    if (this->is_listening) {
        this->amplitude_storage->push_back(i);
        if (this->amplitude_storage->size() > this->storage_maxlength) {
            this->amplitude_storage->erase(this->amplitude_storage->begin());
        }
    }
}

void Listener::ListeningBegin() {
    this->is_listening = true;
}

void Listener::ListeningEnd() {
    this->is_listening = false;
}