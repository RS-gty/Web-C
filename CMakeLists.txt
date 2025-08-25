cmake_minimum_required(VERSION 3.31)
project(Web25)

include_directories("D:\\Projects\\C++\\libs\\boost_1_88_0")
include_directories("D:\\Projects\\C++\\libs\\eigen-3.4.0")
include_directories("D:\\Projects\\C++\\libs\\opencv-4.12.0")

set(CMAKE_CXX_STANDARD 26)

add_executable(Web25 main.cpp
        Server/Server.cpp
        Server/Server.h
        Server/SubServer.cpp
        Env/Environment.cpp
        Env/Environment.h
        Server/Host.cpp
        Signal/Signal.cpp
        Signal/Signal.h
        Algorithm/BinaryTree/BinaryTree.cpp
        Algorithm/BinaryTree/BinaryTree.h
        utils/utils.cpp
        utils/utils.h
        Algorithm/ClassCoder/ClassCoder.h
        Physics/Objects/Particle.cpp
        Physics/Objects/Particle.h
        Physics/Fields/Field.cpp
        Physics/Fields/Field.h
        Physics/Fields/ConstGravityField.cpp
        Physics/Fields/MagneticField.cpp
        Physics/Fields/GravityField.cpp
        Algorithm/FFT/fft.cpp)
