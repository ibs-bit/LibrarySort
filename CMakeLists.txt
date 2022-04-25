cmake_minimum_required(VERSION 3.21)
project(LibrarySort)

set(CMAKE_CXX_STANDARD 14)

add_executable(LibrarySort main.cpp Book.cpp Book.h BST.cpp BST.h Tasks.cpp Tasks.h)
