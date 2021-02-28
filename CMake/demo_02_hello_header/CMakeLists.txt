
cmake_minimum_required(VERSION 3.10.2)

project (hello_header)

set(SOURCE_FILES
    src/hello.cpp
    src/main.cpp
)

add_executable(hello_header ${SOURCE_FILES})

target_include_directories(hello_header
    PRIVATE 
        ${PROJECT_SOURCE_DIR}/inc
)
