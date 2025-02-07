cmake_minimum_required(VERSION 3.5)

project(app)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(PROJECTS
lib
program-1
)

foreach(PROJECT ${PROJECTS})
    add_subdirectory(${PROJECT})
endforeach()

#add_custom_target(RunAllPrograms
#    COMMAND $<TARGET_FILE:lib>
#    COMMAND $<TARGET_FILE:program-1>
#    DEPENDS ${PROJECTS}
#)
