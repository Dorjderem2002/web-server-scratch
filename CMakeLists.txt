cmake_minimum_required(VERSION 3.5)
project(Web_Server)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add all .cpp files in the src directory to the SOURCES variable
file(GLOB SOURCES "src/*.cpp" "src/socket/*.cpp" "src/server/*.cpp")

# Add an executable target for the project
add_executable(server ${SOURCES})