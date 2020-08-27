cmake_minimum_required(VERSION 3.5)

# set the project name
project(library, VERSION 0.0.1)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)


############################################################
# Create a library
############################################################

#Generate the static library from the library sources
add_library(library STATIC 
    ./compute.cpp
)

# 如果header文件和源文件不在同一个路径下，则需要指定header文件的路径
# target_include_directories(hello_library
#     PUBLIC 
#         ${PROJECT_SOURCE_DIR}/include
# )


############################################################
# Create an executable
############################################################

# Add an executable with the above sources
add_executable(main
    ./main.cpp
)

# link the new hello_library target with the hello_binary target
target_link_libraries( main
    PRIVATE 
        library
)
