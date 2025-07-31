//
// Created by ADMIN on 25-7-23.
//

#ifndef WEB_ENVIRONMENT_H
#define WEB_ENVIRONMENT_H

#include "../Algorithm/BinaryTree/BinaryTree.h"
#include "../Signal/Signal.h"
#include <Eigen/Dense>

using namespace Eigen;

class Environment {
public:
    Environment();
    void addSignal(const Signal& s){};

private:
    BinaryTree SubServers = new BinaryNode();
    BinaryTree Hosts = new BinaryNode();
    BinaryTree Signals = new BinaryNode();
};


#endif//WEB_ENVIRONMENT_H
