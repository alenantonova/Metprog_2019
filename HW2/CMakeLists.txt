cmake_minimum_required(VERSION 3.15)
project(untitled)

set(CMAKE_CXX_STANDARD 14)

add_executable(untitled main.cpp ChairModels.h TableModels.h SofaModels.h Furniture.h TypeListUtils.h FactoryUtils.h)