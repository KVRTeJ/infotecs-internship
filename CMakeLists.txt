cmake_minimum_required(VERSION 3.5)

project(infotecs-internship)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(PROJECTS
lib
program-1
program-2
)

foreach(PROJECT ${PROJECTS})
    add_subdirectory(${PROJECT})
endforeach()
