cmake_minimum_required(VERSION 3.17)
project(Girvan-Newman) # Auto generated don't edit

set(CMAKE_CXX_STANDARD 17) # Required version by Dr. Fontenot
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")

set(Sources src/main.cpp
            src/reader.hpp
            src/reader.cpp)

FIND_PACKAGE(Boost)

IF (Boost_FOUND)
    message("FOUND")
endif()

if(NOT Boost_FOUND)
    message(FATAL_ERROR "Boost Not found")
endif()

add_executable(${PROJECT_NAME} ${Sources})

INCLUDE_DIRECTORIES(${Boost_INCLUDE_DIR})

