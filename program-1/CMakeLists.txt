cmake_minimum_required(VERSION 3.5)

project(program-1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(program-1 main.cpp
    container.h
    recipient.h recipient.cpp
    dispatcher.h dispatcher.cpp
    idispatcher.h

)
target_link_libraries(program-1 lib)

include(GNUInstallDirs)
install(TARGETS program-1
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
