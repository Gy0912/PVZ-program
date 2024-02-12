cmake_minimum_required(VERSION 3.16)

add_library(
  Repeater
  STATIC
  Repeater.hpp
  Repeater.cpp
)

target_link_libraries(
  Repeater
  GameObject
)

target_include_directories(
  Repeater
  PUBLIC 
  ${CMAKE_SOURCE_DIR}/src/GameObject/
  ${CMAKE_SOURCE_DIR}/src/Repeater/
  )