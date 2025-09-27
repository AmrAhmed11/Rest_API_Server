cmake_minimum_required(VERSION 3.28)
project(Rest_API_Server)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Boost REQUIRED COMPONENTS system)

add_executable(Server main.cpp)