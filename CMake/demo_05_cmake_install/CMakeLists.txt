
cmake_minimum_required(VERSION 3.10.2)

project(cmake_examples_install)


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


############################################################
# Create an executable
############################################################

# Add an executable with the above sources
add_executable(cmake_install
    src/main.cpp
)

# link the new hello_library target with the hello_binary target
target_link_libraries(cmake_install
    PRIVATE
        new_shared_library
)


############################################################
# Install
############################################################

# Binaries
install(TARGETS cmake_install
    DESTINATION bin)

# Library
install(TARGETS new_shared_library
    LIBRARY DESTINATION lib)

# Header files
install(DIRECTORY ${PROJECT_SOURCE_DIR}/inc/ 
    DESTINATION include)

# Config
install (FILES cmake-examples.conf
    DESTINATION etc)
