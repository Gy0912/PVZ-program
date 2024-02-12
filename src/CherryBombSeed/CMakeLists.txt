cmake_minimum_required(VERSION 3.16)

add_library(
  CherryBombSeed
  STATIC
  CherryBombSeed.hpp
  CherryBombSeed.cpp
)

target_link_libraries(
  CherryBombSeed
  GameObject
  CooldownMask
)

target_include_directories(
  CherryBombSeed
  PUBLIC 
  ${CMAKE_SOURCE_DIR}/src/GameObject/
  ${CMAKE_SOURCE_DIR}/src/CherryBombSeed/
  ${CMAKE_SOURCE_DIR}/src/CooldownMask/
)