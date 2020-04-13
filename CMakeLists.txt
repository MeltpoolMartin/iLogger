cmake_minimum_required(VERSION 3.17.0)

project(iLogger VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 11)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/src/logging
                    ${CMAKE_CURRENT_SOURCE_DIR}/src/interface
                    ${CMAKE_CURRENT_SOURCE_DIR}/3rdParty/spdlog/include)

set(SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/src/logging/LogHandler.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/src/logging/SpdlogHandler.cpp)

add_executable(iLogger ${SOURCES})