cmake_minimum_required(VERSION 3.10)

project(FileParser)

set(CMAKE_CXX_STANDARD 20)
set(PROJECT_DIR ${CMAKE_SOURCE_DIR})
set(PROJECT_INCLUDE_DIR ${PROJECT_DIR}/include)
set(PROJECT_SOURCE_DIR ${PROJECT_DIR}/src)
set(PROJECT_EXAMPLE_DIR ${PROJECT_DIR}/examples)

set(PROJECT_SOURCES 
            ${PROJECT_EXAMPLE_DIR}/test.cpp
            ${PROJECT_SOURCE_DIR}/fileparser.cpp
    )

set(PROJECT_HEADERS
        ${PROJECT_INCLUDE_DIR}/fileparser.hpp    
    )


include_directories(${PROJECT_INCLUDE_DIR})

add_executable(${PROJECT_NAME} ${PROJECT_SOURCES})

