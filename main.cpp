#define _CRT_STDIO_ISO_WIDE_SPECIFIERS
#define MGL_STATIC_DEFINE

#include "Algorithm/BinaryTree/BinaryTree.h"
#include "Env/Environment.h"
#include "Server/Server.h"
#include "Signal/Signal.h"
#include "utils/utils.h"
#include "Physics/Objects/Particle.h"
#include "Physics/Fields/Field.h"


#include <iostream>
#include <thread>

using namespace std;

typedef long long int lint;
typedef long double ld;

atomic<bool> running = true;
queue<string> commands;
mutex queue_mutex;

void input_thread(Environment &env) {
    string cmd;
    while (running) {
        cout << "Enter command: ";
        getline(cin, cmd);

        lock_guard<mutex> lock(queue_mutex);
        commands.push(cmd);

        if (cmd == "help") {
            cout << "Available commands: help, status, exit\n";
        } else if (cmd == "status") {
            cout << "System is running...\niteration:" + to_string(env.iter) << "\n";
        } else if (cmd == "exit") {
            running = false;
        } else {
            cout << "Unknown command.\ntype \"help\" to find available commands\n";
        }
    }
}

void simulate_begin(Environment &env) {
    thread input_handler(input_thread, ref(env));

    while (running) {
        // 主循环的工作
        env.Update();
        // 处理输入命令
        lock_guard<mutex> lock(queue_mutex);
        while (!commands.empty()) {
            string cmd = commands.front();
            commands.pop();
            // 处理其他命令...
        }
    }

    input_handler.join();
    cout << "Program terminated\n";
}

/* Main Physics Properties and Default Scale Settings:
 * 1.(double) 1.0 of distance === 1s * c === 300000km
 *
 *
 *
 *
 *
 *
 */

lint global_iterator = 0;
ld global_time_counter = 0; // unit:second
ld long_fract = static_cast<long double>(1) / static_cast<long double>(1048576);


int main() {
    Particle p1(1, {1, 2, 3}, {1, 0, 0}, 1);

    ConstGravityField G1(10, {0, 0, -1});
    MagneticField M1(1, {0, 0, 1});
    GravityField G2(5, {1, 0, 2});

    Environment env(long_fract * 1024);

    Host h1(env, 1, -1234, 3);
    h1.SetSignal(1, 2, 0);

    h1.BindPosition(p1);
    env.appendField(&G2);
    env.appendParticle(p1);

    simulate_begin(env);

    cout << env.getSignalIntensity(h1.getPosition()) << endl;

    cout << "iteration:" + to_string(env.getIteration()) << endl;
    cout << "position of simulated space station" << endl;
    cout << h1.getPosition() << endl;

    double space[200][200];
    std::chrono::high_resolution_clock::time_point t0 = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < 200; i++) {
        for (int j = 0; j < 200; j++) {
            space[i][j] = env.getSignalIntensity(static_cast<double>(i) / 10, static_cast<double>(j) / 10, 0);
        }
    }
    std::chrono::high_resolution_clock::time_point t1 = std::chrono::high_resolution_clock::now();
    cout << t1 - t0 << endl;


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

    cout << s2.get_pointer() << endl;
    cout << s2.get_pointer()->get_origin() << endl;
    cout << static_cast<string>(s2) << endl;
    cout << MemoryValue<Signal>(ExtractMemory(static_cast<string>(s2))).get_origin() << endl;
    cout <<"faded"<<endl;
*/

    return 0;
}
