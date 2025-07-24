#include "Algorithm/BinaryTree/BinaryTree.h"
#include "Env/Environment.h"
#include "Server/Server.h"
#include "Signal/Signal.h"
#include <chrono>
#include <iostream>

using namespace std;



int main() {
    Host h(1, 2, 3, 4);
    Signal s(1, 2, 3 );
    Signal s2(10, 2, 3 );

    Vector3d v(1, 2, 3);

    s.set_origin(v);

    vector<string> strs = {"asdf", "msas", "qweg", "bnjd", "sfhj", "hote", "sjbn"};

    BinaryTree Tree = SetBinaryTree(strs);

    DeleteData(Tree, "msas");

    Find(Tree, "msas");
    vector<Signal> container;
    return 0;
}
