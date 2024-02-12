cmake_minimum_required(VERSION 3.16)

add_library(
  WallNut
  STATIC
  WallNut.hpp
  WallNut.cpp
)

target_link_libraries(
  WallNut
  GameObject
)

target_include_directories(
  WallNut
  PUBLIC 
  ${CMAKE_SOURCE_DIR}/src/GameObject/
  ${CMAKE_SOURCE_DIR}/src/WallNut/
)