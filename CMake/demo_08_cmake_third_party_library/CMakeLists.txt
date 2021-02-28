
cmake_minimum_required(VERSION 3.10.2)

# Set the project name
project (cmake_third_party_library)


# find a boost install with the libraries filesystem and system
find_package(Boost 1.46.1 REQUIRED COMPONENTS filesystem system)

# check if boost was found
if(Boost_FOUND)
    message ("Boost found. By Leuckart.")
else()
    message (FATAL_ERROR "Cannot find Boost. By Leuckart.")
endif()


# Add an executable
add_executable(cmake_third_party_library main.cpp)

# link against the boost libraries
target_link_libraries(cmake_third_party_library
    PRIVATE
        Boost::filesystem
)
