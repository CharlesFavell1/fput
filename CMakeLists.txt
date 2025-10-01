cmake_minimum_required(VERSION 4.0)
project(fput)

set(CMAKE_CXX_STANDARD 20)

add_executable(fput main.cpp
        include/physics/Hamiltonian.h
        include/physics/State.h
        include/physics/FPUTHamiltonian.h
        src/physics/State.cpp
        src/physics/FPUTHamiltonian.cpp
        include/physics/Connectivity.h
        src/physics/LinearLattice.cpp
        include/physics/LinearLattice.h
)
