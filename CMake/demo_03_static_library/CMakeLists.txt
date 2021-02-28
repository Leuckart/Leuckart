
cmake_minimum_required(VERSION 3.10.2)

project(hello_static_library)


############################################################
# Create a library
############################################################

#Generate the static library from the library sources
add_library(new_static_library
    STATIC
        src/hello.cpp
)

target_include_directories(new_static_library
    PUBLIC
        ${PROJECT_SOURCE_DIR}/inc
)


############################################################
# Create an executable
############################################################

# Add an executable with the above sources
add_executable(hello_static_library
    src/main.cpp
)

# link the new hello_library target with the hello_binary target
target_link_libraries(hello_static_library
    PRIVATE
        new_static_library
)
