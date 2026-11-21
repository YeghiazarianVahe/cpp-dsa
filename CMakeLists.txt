cmake_minimum_required(VERSION 3.20)
project(cpp_dsa LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Catch2-ը բեռնվում է նախքան warning-ների ավելացումը, որ իր կոդի վրա չդժգոհի
include(FetchContent)
FetchContent_Declare(
  Catch2
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG        v3.7.1
)
FetchContent_MakeAvailable(Catch2)

add_compile_options(-Wall -Wextra -Wpedantic -Wconversion)

enable_testing()
add_subdirectory(vector)
