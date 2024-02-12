cmake_minimum_required(VERSION 3.16)

add_library(
  SunFlower
  STATIC
  SunFlower.hpp
  SunFlower.cpp
)

target_link_libraries(
  SunFlower
  GameObject
  SunFromFlower
)

target_include_directories(
  SunFlower
  PUBLIC 
  ${CMAKE_SOURCE_DIR}/src/GameObject/
  ${CMAKE_SOURCE_DIR}/src/SunFlower/
  ${CMAKE_SOURCE_DIR}/src/SunFromFlower/
)