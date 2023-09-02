cmake_minimum_required(VERSION 3.0)
project(MyProject)

# Include directories
include_directories(${CMAKE_SOURCE_DIR}/include)

# Gather all .cpp files recursively
file(GLOB_RECURSE SRC_FILES "${CMAKE_SOURCE_DIR}/src/*.cpp" "${CMAKE_SOURCE_DIR}/subdirectories/*.cpp")

# Create executable from the gathered .cpp files
add_executable(myprogram ${SRC_FILES})

# Link with MySQL Connector/C++ library
target_link_libraries(myprogram mysqlcppconn)
