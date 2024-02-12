cmake_minimum_required(VERSION 3.16)

add_library(
  PeaShooter
  STATIC
  PeaShooter.hpp
  PeaShooter.cpp
)

target_link_libraries(
  PeaShooter
  GameObject
  Zombie
  Pea
)

target_include_directories(
  PeaShooter
  PUBLIC 
  ${CMAKE_SOURCE_DIR}/src/GameObject/
  ${CMAKE_SOURCE_DIR}/src/PeaShooter/
  ${CMAKE_SOURCE_DIR}/src/Zombie/
  ${CMAKE_SOURCE_DIR}/src/Pea/
)