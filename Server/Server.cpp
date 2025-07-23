//
// Created by ADMIN on 25-7-23.
//

#include "Server.h"
#include <string>

#include <boost/uuid/uuid_generators.hpp>
#include <boost/uuid/uuid_io.hpp>
#include <utility>

using namespace std;
using namespace Eigen;

Server::Server(Vector3d pos) {
    boost::uuids::random_generator generator;
    identifier = to_string(generator());
    position = std::move(pos);
}


Server::Server(double x, double y, double z) {
    boost::uuids::random_generator generator;
    identifier = to_string(generator());
    position = Vector3d(x, y, z);
}

string Server::get_id() {
    return identifier;
}

