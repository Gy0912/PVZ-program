cmake_minimum_required(VERSION 3.16)

add_library(
  SunFlowerSeed
  STATIC
  SunFlowerSeed.hpp
  SunFlowerSeed.cpp
)

target_link_libraries(
  SunFlowerSeed
  GameObject
  CooldownMask
)

target_include_directories(
  SunFlowerSeed
  PUBLIC 
  ${CMAKE_SOURCE_DIR}/src/GameObject/
  ${CMAKE_SOURCE_DIR}/src/SunFlowerSeed/
  ${CMAKE_SOURCE_DIR}/src/CooldownMask/
)