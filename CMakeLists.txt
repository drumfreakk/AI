cmake_minimum_required(VERSION 3.13)
project(AI)

set(CMAKE_CXX_STANDARD 17)

add_executable(AI 	main.cpp
					libs/Matrix.cpp
					libs/Matrix.h)