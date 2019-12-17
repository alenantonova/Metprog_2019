cmake_minimum_required(VERSION 3.15)
project(Hw3MetProg)

set(CMAKE_CXX_STANDARD 11)

add_executable(Hw3MetProg main.cpp Functor.h VisitFactory.h Acceptor.h Visitor.h BankExchange.h TypeListUtils.h)