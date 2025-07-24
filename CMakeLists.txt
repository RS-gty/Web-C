cmake_minimum_required(VERSION 3.28)
project(Web)

include_directories("E:\\Programs\\C++\\libs\\boost_1_88_0")
include_directories("E:\\Programs\\C++\\libs\\eigen-3.4.0")

set(CMAKE_CXX_STANDARD 26)

add_executable(Web main.cpp
        Server/Server.cpp
        Server/Server.h
        Server/SubServer.cpp
        Env/Environment.cpp
        Env/Environment.h
        Server/Host.cpp
        Signal/Signal.cpp
        Signal/Signal.h
        Algorithm/BinaryTree/BinaryTree.cpp
        Algorithm/BinaryTree/BinaryTree.h)
