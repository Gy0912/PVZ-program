cmake_minimum_required(VERSION 3.16)

add_library(
  WallNutSeed
  STATIC
  WallNutSeed.hpp
  WallNutSeed.cpp
)

target_link_libraries(
  WallNutSeed
  GameObject
  CooldownMask
)

target_include_directories(
  WallNutSeed
  PUBLIC 
  ${CMAKE_SOURCE_DIR}/src/GameObject/
  ${CMAKE_SOURCE_DIR}/src/WallNutSeed/
  ${CMAKE_SOURCE_DIR}/src/CooldownMask/
)