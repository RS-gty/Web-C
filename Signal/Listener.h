//
// Created by RSgty on 25-8-26.
//

#ifndef LISTENER_H
#define LISTENER_H

#include <vector>
#include <Eigen/Dense>

using namespace std;
using namespace Eigen;


class Listener {
public:
    Listener(Vector3d &position, vector<double> &amplitude_storage, int storage_maxlength);

    void setPosition(Vector3d *pos);

    void Listen();

    void ListeningBegin();

    void ListeningEnd();

    bool is_listening = true;

    vector<double> *amplitude_storage;
    Vector3d *position;
    int storage_maxlength;

};



#endif //LISTENER_H
