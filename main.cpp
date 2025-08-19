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

void input_thread() {
    std::string cmd;
    while (running) {
        std::cout << "Enter command: ";
        std::getline(std::cin, cmd);

        std::lock_guard<std::mutex> lock(queue_mutex);
        commands.push(cmd);

        if (cmd == "exit") running = false;
    }
}

void simulate_begin(Simulation &sim) {
    std::thread input_handler(input_thread);

    while (running) {
        // 主循环的工作
        sim.update();

        // 处理输入命令
        std::lock_guard<std::mutex> lock(queue_mutex);
        while (!commands.empty()) {
            std::string cmd = commands.front();
            commands.pop();

            if (cmd == "help") {
                std::cout << "Available commands: help, status, exit\n";
            } else if (cmd == "status") {
                std::cout << "System is running...\n";
            }
            // 处理其他命令...
        }
    }

    input_handler.join();
    std::cout << "Program terminated\n";
}

int main() {
    Particle p1(1, {1, 2, 3}, {1, 0, 0}, 1);

    ConstGravityField G1(10, {0, 0, -1});
    MagneticField M1(1, {0, 0, 1});
    GravityField G2(5, {1, 0, 2});

    Environment env;

    Host h1(env, 1, -1234, 3);

    h1.BindPosition(p1);


    Simulation simulation{};
    simulation.appendField(&G2);
    simulation.appendParticle(p1);

    bool running = true;

    simulate_begin(simulation);

    cout << p1.position << endl;
    cout << h1.getPosition() << endl;

    /*
    Environment env;



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