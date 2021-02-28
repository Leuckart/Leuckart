# cmake .. -G Ninja
# ninja -v

cmake_minimum_required(VERSION 3.10.2)

# Set the project name
project (cmake_using_ninja)

# Add an executable
add_executable(cmake_using_ninja main.cpp)
