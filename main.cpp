#include "Algorithm/BinaryTree/BinaryTree.h"
#include "Env/Environment.h"
#include "Server/Server.h"
#include "Signal/Signal.h"
#include "utils/utils.h"
#include "Physics/Objects/Particle.h"
#include "Physics/Fields/Field.h"
#include "Physics/Simulation/Simulation.h"

#include <boost/uuid/uuid_generators.hpp>
#include <boost/uuid/uuid_io.hpp>
#include <iostream>
#include <thread>

using namespace std;

atomic<bool> running = true;
queue<std::string> commands;
mutex queue_mutex;

int main() {
    Particle p1(1, {1, 2, 3}, {0, 0, 0});

    ConstGravityField G1(10, {0, 0, -1});

    std::vector<Field*> fs;




    Simulation simulation{};
    simulation.appendField(&G1);
    simulation.appendParticle(p1);

    bool running = true;

    simulation.simulate_begin(running, 0.001);

    cout << p1.position << endl;

    /*
    Environment env;

    Host h1(env, 1, 2, 3);

    Host h2(env, 2, 2, 3);

    h1.SetSignal(2.7182818, 2, 3);

    Vector3d v(1, 2, 3);

    static vector<string> strs = {};

    boost::uuids::random_generator generator;
    for (int i = 0; i < 10; i++) {
        strs.push_back(to_string(generator()));
    }


    BinaryTree Tree = SetBinaryTree(strs);

    string s = "hello world";

    vector<Signal> container;
/*
    cout << s2.get_pointer() << endl;
    cout << s2.get_pointer()->get_origin() << endl;
    cout << static_cast<string>(s2) << endl;
    cout << MemoryValue<Signal>(ExtractMemory(static_cast<string>(s2))).get_origin() << endl;
    cout <<"faded"<<endl;
*/

    return 0;
}