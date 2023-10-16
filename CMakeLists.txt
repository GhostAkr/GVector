cmake_minimum_required(VERSION 3.27.0)
project(GVector VERSION 0.1.0 LANGUAGES C CXX)

set(INC_DIR inc)
set(SRC_DIR src)

set(HEADERS ${INC_DIR}/gvector.hpp)

set(SOURCES
    ${SRC_DIR}/gvector.cpp
    ${SRC_DIR}/main.cpp)

add_executable(GVector ${HEADERS} ${SOURCES})
