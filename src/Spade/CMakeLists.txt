cmake_minimum_required(VERSION 3.16)

add_library(
  Spade
  STATIC
  Spade.hpp
  Spade.cpp
)

target_link_libraries(
  Spade
  GameObject
)

target_include_directories(
  Spade
  PUBLIC 
  ${CMAKE_SOURCE_DIR}/src/GameObject/
   ${CMAKE_SOURCE_DIR}/src/Spade/
)