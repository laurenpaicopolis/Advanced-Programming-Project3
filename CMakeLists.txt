cmake_minimum_required(VERSION 3.8)
project(LP-Project3)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -Werror=return-type")

add_executable(LP-Project3 Player.cpp Player.h SkierSnowboarder.cpp SkierSnowboarder.h VTMountain.h VTMountain.cpp main.cpp
        critic.cpp critic.h)

add_executable(Project3Testing-LP testing.cpp Player.cpp Player.h SkierSnowboarder.cpp SkierSnowboarder.h VTMountain.h VTMountain.cpp
        critic.cpp critic.h)