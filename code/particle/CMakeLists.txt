cmake_minimum_required(VERSION 3.16)

project(particle CXX)
enable_testing()

add_executable(particle main.cpp ParticleType.cpp ResonanceType.cpp Particle.cpp) 
target_compile_options(particle PRIVATE -std=c++17 -Wall -Wextra)
