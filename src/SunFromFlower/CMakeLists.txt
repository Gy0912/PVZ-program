cmake_minimum_required(VERSION 3.16)

add_library(
  SunFromFlower
  STATIC
  SunFromFlower.hpp
  SunFromFlower.cpp
)

target_link_libraries(
  SunFromFlower
  GameObject
)

target_include_directories(
  SunFromFlower
  PUBLIC 
  ${CMAKE_SOURCE_DIR}/src/GameObject/
  ${CMAKE_SOURCE_DIR}/src/SunFromFlower/
)