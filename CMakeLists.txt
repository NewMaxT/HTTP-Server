cmake_minimum_required(VERSION 3.28)
project(HTTP_Server)

set(CMAKE_CXX_STANDARD 20)

if (WIN32)
    link_libraries (ws2_32 wsock32)
endif (WIN32)

add_executable(HTTP_Server "main.cpp"
        TCP_Server.cpp
        TCP_Server.h)
