cmake_minimum_required(VERSION 3.5)

# set the project name
project(library, VERSION 0.0.1)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# 设置输出路径
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/release/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/release/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/release/bin)

# 等价于上方三行代码
# set_target_properties( targets...
#     PROPERTIES
#     ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/release/lib"
#     LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/release/lib"
#     RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/release/bin"
# )

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

