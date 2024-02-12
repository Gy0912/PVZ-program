cmake_minimum_required(VERSION 3.16)

add_library(
  SunFromSky
  STATIC
  SunFromSky.hpp
  SunFromSky.cpp
)

target_link_libraries(
  SunFromSky
  GameObject
)

target_include_directories(
  SunFromSky
  PUBLIC 
  ${CMAKE_SOURCE_DIR}/src/GameObject/
  ${CMAKE_SOURCE_DIR}/src/SunFromSky/
)