cmake_minimum_required(VERSION 3.16)

add_library(
  Background
  STATIC
  Background.hpp
  Background.cpp
)

target_link_libraries(
  Background
  GameObject
)

target_include_directories(
  Background
  PUBLIC 
  ${CMAKE_SOURCE_DIR}/src/GameObject/
   ${CMAKE_SOURCE_DIR}/src/Background/
)