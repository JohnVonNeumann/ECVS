cmake_minimum_required(VERSION 3.19)
project(ECVS)

set(CMAKE_CXX_STANDARD 20)

add_executable(ECVS main.cpp voter.cpp candidate.cpp voter.h candidate.h main.h)