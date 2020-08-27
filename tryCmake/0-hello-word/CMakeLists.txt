cmake_minimum_required(VERSION 3.5)

# set the project name
project(tryCMake, VERSION 0.0.1)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# add the executable
add_executable(tryCMake tutorial.cxx)