cmake_minimum_required(VERSION 3.16)

add_library(
  RepeaterSeed
  STATIC
  RepeaterSeed.hpp
  RepeaterSeed.cpp
)

target_link_libraries(
  RepeaterSeed
  GameObject
  CooldownMask
)

target_include_directories(
  RepeaterSeed
  PUBLIC 
  ${CMAKE_SOURCE_DIR}/src/GameObject/
  ${CMAKE_SOURCE_DIR}/src/RepeaterSeed/
  ${CMAKE_SOURCE_DIR}/src/CooldownMask/
)