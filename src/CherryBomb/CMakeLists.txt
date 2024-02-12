cmake_minimum_required(VERSION 3.16)

add_library(
  CherryBomb
  STATIC
  CherryBomb.hpp
  CherryBomb.cpp
)

target_link_libraries(
  CherryBomb
  GameObject
  Explosion
)

target_include_directories(
  CherryBomb
  PUBLIC 
  ${CMAKE_SOURCE_DIR}/src/GameObject/
  ${CMAKE_SOURCE_DIR}/src/CherryBomb/
  ${CMAKE_SOURCE_DIR}/src/Explosion/
)