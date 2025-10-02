cmake_minimum_required(VERSION 3.20)
project(fput LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_library(fput_lib
        src/physics/State.cpp
        src/physics/FPUTHamiltonian.cpp
        src/physics/LinearLattice.cpp
)

target_include_directories(fput_lib PUBLIC include)

add_executable(fput
        main.cpp
)

target_link_libraries(fput PRIVATE fput_lib)
