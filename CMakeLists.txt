cmake_minimum_required(VERSION 3.27.0)
project(GVector VERSION 0.1.0 LANGUAGES C CXX)
######

set(INC_DIR inc)
set(SRC_DIR src)

set(HEADERS 
    ${INC_DIR}/gvector.h)

set(SOURCES
    ${SRC_DIR}/main.cpp
    ${SRC_DIR}/gvector.cpp)

add_executable(GVector ${HEADERS} ${SOURCES})
