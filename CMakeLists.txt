cmake_minimum_required(VERSION 3.28)
project(Rest_API_Server)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(Server src/main.cpp)

find_package(Boost REQUIRED COMPONENTS system)
find_package(nlohmann_json 3.2.0)

target_include_directories(Server PRIVATE include)
target_link_libraries(Server PRIVATE Boost::system)

