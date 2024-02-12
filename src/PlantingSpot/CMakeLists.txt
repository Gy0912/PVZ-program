cmake_minimum_required(VERSION 3.16)

add_library(
  PlantingSpot
  STATIC
  PlantingSpot.hpp
  PlantingSpot.cpp
)

target_link_libraries(
  PlantingSpot
  GameObject
  SunFlower
  PeaShooter
  Repeater
  CherryBomb
  WallNut
)

target_include_directories(
  PlantingSpot
  PUBLIC 
  ${CMAKE_SOURCE_DIR}/src/GameObject/
  ${CMAKE_SOURCE_DIR}/src/PlantingSpot/
  ${CMAKE_SOURCE_DIR}/src/SunFlower/
  ${CMAKE_SOURCE_DIR}/src/PeaShooter/
  ${CMAKE_SOURCE_DIR}/src/Repeater/
  ${CMAKE_SOURCE_DIR}/src/CherryBomb/
  ${CMAKE_SOURCE_DIR}/src/WallNut/
)