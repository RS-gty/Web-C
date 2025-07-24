#include "Algorithm/BinaryTree/BinaryTree.h"
#include "Env/Environment.h"
#include "Server/Server.h"
#include "Signal/Signal.h"
#include <boost/uuid/uuid_generators.hpp>
#include <boost/uuid/uuid_io.hpp>
#include <chrono>
#include <iostream>

using namespace std;


int main() {
    Host h(1, 2, 3, 4);
    Signal s(1, 2, 3);
    Signal s2(10, 2, 3);

    Vector3d v(1, 2, 3);

    s.set_origin(v);

    vector<string> strs = {};

    boost::uuids::random_generator generator;
    for (int i = 0; i < 10; i++) {
        strs.push_back(to_string(generator()));
    }


    auto Tree = SetBinaryTree(strs);


    PreOrderTraverse(Tree);
    Find(Tree, strs[6]);
    vector<Signal> container;
    return 0;
}
