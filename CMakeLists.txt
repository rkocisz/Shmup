cmake_minimum_required(VERSION 3.21)

project(Shmup)

include(FetchContent)

set(FETCHCONTENT_QUIET FALSE)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

option(BUILD_SHARED_LIBS "Build shared libraries" OFF)

FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 2.6.x)
FetchContent_MakeAvailable(SFML)

file(GLOB_RECURSE SHMUP_SRC src/*.*)

add_executable(Shmup ${SHMUP_SRC})

target_link_libraries(Shmup PRIVATE sfml-graphics)

target_compile_features(Shmup PRIVATE cxx_std_17)
