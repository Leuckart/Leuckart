# cmake .. -DCMAKE_C_COMPILER=/home/leuckart/LLVM/bin/clang -DCMAKE_CXX_COMPILER=clang++
# make

cmake_minimum_required(VERSION 3.10.2)

# Set the project name
project (cmake_using_clang)

# Add an executable
add_executable(cmake_using_clang main.cpp)
