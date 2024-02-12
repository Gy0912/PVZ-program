cmake_minimum_required(VERSION 3.16)

add_library(
  Pea
  STATIC
  Pea.hpp
  Pea.cpp
)

target_link_libraries(
  Pea
  GameObject
)

target_include_directories(
  Pea
  PUBLIC 
  ${CMAKE_SOURCE_DIR}/src/GameObject/
   ${CMAKE_SOURCE_DIR}/src/Pea/
)