# Minimum CMake version required
cmake_minimum_required(VERSION 3.12)

# Name of the project
project(WavPlayer)

# Use C++14
set(CMAKE_CXX_STANDARD 14)

# Find pybind11, required for Python bindings
find_package(pybind11 REQUIRED)

# Define a shared library (Python module) named 'wav_player'
add_library(wav_player MODULE
    src/wav_player.cpp
    src/wav_player_pybind.cpp
)

# Include our header files
target_include_directories(wav_player PRIVATE ${CMAKE_SOURCE_DIR}/include)

# Link pybind11 to our module
target_link_libraries(wav_player PRIVATE pybind11::module)

# Remove the 'lib' prefix and set the suffix to '.so' (Python expects this format)
set_target_properties(wav_player PROPERTIES PREFIX "" SUFFIX ".so")

# Automatically move wav_player.so to the project root directory after build
add_custom_command(TARGET wav_player POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy
            $<TARGET_FILE:wav_player>
            ${CMAKE_SOURCE_DIR}/wav_player.so
    COMMENT "Moving wav_player.so to project root directory"
)