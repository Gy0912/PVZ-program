cmake_minimum_required(VERSION 3.16)

add_library(
  PeaShooterSeed
  STATIC
  PeaShooterSeed.hpp
  PeaShooterSeed.cpp
)

target_link_libraries(
  PeaShooterSeed
  GameObject
  CooldownMask
)

target_include_directories(
  PeaShooterSeed
  PUBLIC 
  ${CMAKE_SOURCE_DIR}/src/GameObject/
  ${CMAKE_SOURCE_DIR}/src/PeaShooterSeed/
  ${CMAKE_SOURCE_DIR}/src/CooldownMask/
)