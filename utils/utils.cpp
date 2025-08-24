//
// Created by ADMIN on 25-7-25.
//

#include "utils.h"

using namespace std;

string ExtractMemory(string storage) {
    return storage.substr(36);
};

string RandomUUID() {
    boost::uuids::random_generator generator;
    return to_string(generator());
}
