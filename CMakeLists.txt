cmake_minimum_required(VERSION 3.28)
project(Rest_API_Server)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Boost REQUIRED COMPONENTS system)
find_package(nlohmann_json 3.2.0)

add_executable(Server main.cpp)