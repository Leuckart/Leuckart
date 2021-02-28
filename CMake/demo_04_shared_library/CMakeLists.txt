
cmake_minimum_required(VERSION 3.10.2)

project(hello_shared_library)


############################################################
# Create a library
############################################################

#Generate the shared library from the library sources
add_library(new_shared_library
    SHARED 
        src/hello.cpp
)

target_include_directories(new_shared_library
    PUBLIC 
        ${PROJECT_SOURCE_DIR}/inc
)

add_library(hello::library ALIAS new_shared_library)

############################################################
# Create an executable
############################################################

# Add an executable with the above sources
add_executable(hello_shared_binary
    src/main.cpp
)

# link the new hello_library target with the hello_binary target
target_link_libraries(hello_shared_binary
    PRIVATE 
        hello::library
)
