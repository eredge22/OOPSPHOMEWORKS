cmake_minimum_required(VERSION 3.10)
project(SafeProject LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_subdirectory(lib)

add_executable(safe_app src/main.cpp)
target_link_libraries(safe_app PRIVATE safe_lib)
