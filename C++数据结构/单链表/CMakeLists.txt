cmake_minimum_required(VERSION 3.10)
project(chain)

set(CMAKE_CXX_STANDARD 11)

add_executable(chain main.cpp Node.cpp Node.h chain.cpp chain.h Chain.cpp Chain.h LinkStack.cpp LinkStack.h)