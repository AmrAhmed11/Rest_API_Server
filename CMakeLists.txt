cmake_minimum_required(VERSION 3.28)
project(Rest_API_Server)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

find_package(Boost REQUIRED COMPONENTS system)
find_package(nlohmann_json 3.2.0)

file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS src/*.cpp)
add_executable(Server ${SOURCES})

target_include_directories(Server PRIVATE include)
target_link_libraries(Server PRIVATE Boost::system)

