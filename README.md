# cmake-exercise
cmake tutorial
https://cmake.org/cmake/help/book/mastering-cmake/cmake/Help/guide/tutorial/index.html

#step1:
cmake项目的最小配置：

cmake_minimum_required(VERSION 3.10)
#set the project name
project(Tutorial)
#add the executable
add_executable(Tutorial tutorial.cpp)

mkdir build
cd build
cmake -G  "Ninja" ..

cmake --build .

./Tutorial 6


目录结构：
step1/
    build/
    CMakeLists.txt
    tutorial.cpp

#step2:
优化 CMakeLists.txt 文件

目录：
step2/
    build/
    CMakeLists.txt
    tutorial.cpp
    TutorialConfig.h.in

#step3: 添加库    








