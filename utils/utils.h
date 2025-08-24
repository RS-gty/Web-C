//
// Created by ADMIN on 25-7-25.
//

#ifndef WEB_UTILS_H
#define WEB_UTILS_H

#include "../Algorithm/BinaryTree/BinaryTree.h"
#include <boost/uuid/random_generator.hpp>
#include <boost/uuid/uuid_io.hpp>
#include <sstream>
#include <string>

using namespace std;

template<typename T>

string MemoryString(T object) {
    void *ss = reinterpret_cast<void *>(&object);
    stringstream s;
    s << ss;
    return s.str();
};

template<typename T>

T MemoryValue(const string &mem) {
    uintptr_t val = std::stoull(mem, nullptr, 16);
    T *ptr = reinterpret_cast<T *>(val);
    return *ptr;
}


template<typename T>

string RandomlizeStroageString(T object) {
    boost::uuids::random_generator generator;
    string id = to_string(generator());
    return id + MemoryString(object);
}

string ExtractMemory(string storage);

string RandomUUID();


#endif//WEB_UTILS_H
