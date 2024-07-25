cmake_minimum_required(VERSION 3.28)
project(pong)

include(FetchContent)
set(BUILD_SHARED_LIBS OFF)
FetchContent_Declare(
        SFML
        GIT_REPOSITORY https://github.com/SFML/SFML.git
        GIT_TAG 2.5.1
)
FetchContent_MakeAvailable(SFML)

set(CMAKE_CXX_STANDARD 17)

# Define tu ejecutable
add_executable(pong main.cpp)

# Vincula SFML a tu ejecutable
target_link_libraries(pong sfml-graphics sfml-window sfml-system sfml-audio)
