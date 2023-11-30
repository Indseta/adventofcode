cmake_minimum_required(VERSION 3.28)
project(Ramlib)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories(${CMAKE_SOURCE_DIR}/include)
link_directories(${CMAKE_SOURCE_DIR}/lib)

file(GLOB_RECURSE SOURCES "${CMAKE_SOURCE_DIR}/src/**/*.cpp" "${CMAKE_SOURCE_DIR}/src/*.cpp")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/run)

add_executable(main ${SOURCES})