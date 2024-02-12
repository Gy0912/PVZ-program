cmake_minimum_required(VERSION 3.16)

add_library(
  GameWorld
  STATIC
  GameWorld.hpp
  GameWorld.cpp
)

target_link_libraries(
  GameWorld
  Framework
  GameObject
  Background
  SunFromSky
  PlantingSpot
  SunFlowerSeed
  PeaShooterSeed
  WallNutSeed
  CherryBombSeed
  RepeaterSeed
  Spade
  Zombie
)

target_include_directories(
  GameWorld
  PUBLIC 
  ${CMAKE_SOURCE_DIR}/src/
  ${CMAKE_SOURCE_DIR}/src/Framework/
  ${CMAKE_SOURCE_DIR}/src/GameObject/
  ${CMAKE_SOURCE_DIR}/src/GameWorld/
  ${CMAKE_SOURCE_DIR}/src/Background/
  ${CMAKE_SOURCE_DIR}/src/SunFromSky/
  ${CMAKE_SOURCE_DIR}/src/PlantingSpot/
  ${CMAKE_SOURCE_DIR}/src/SunFlowerSeed/
  ${CMAKE_SOURCE_DIR}/src/PeaShooterSeed/
  ${CMAKE_SOURCE_DIR}/src/WallNutSeed/
  ${CMAKE_SOURCE_DIR}/src/CherryBombSeed/
  ${CMAKE_SOURCE_DIR}/src/RepeaterSeed/
  ${CMAKE_SOURCE_DIR}/src/Spade/
  ${CMAKE_SOURCE_DIR}/src/Zombie/
)
