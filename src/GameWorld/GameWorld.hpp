#ifndef GAMEWORLD_HPP__
#define GAMEWORLD_HPP__

#include <list>
#include <memory>
#include <cmath>

#include "GameObject.hpp"
#include "WorldBase.hpp"
#include "utils.hpp"
#include "Background.hpp"
#include "SunFromSky.hpp"
#include "PlantingSpot.hpp"
#include "SunFlowerSeed.hpp"
#include "PeaShooterSeed.hpp"
#include "WallNutSeed.hpp"
#include "CherryBombSeed.hpp"
#include "RepeaterSeed.hpp"
#include "Spade.hpp"
#include "Zombie.hpp"

class GameWorld : public WorldBase, public std::enable_shared_from_this<GameWorld>
{
public:
  // Use shared_from_this() instead of "this".
  GameWorld();
  virtual ~GameWorld();

  void Init() override;

  LevelStatus Update() override;

  void CleanUp() override;

  enum class gameobject
  {
    None,
    Spade,
    SunFlower,
    PeaShooter,
    WallNut,
    CherryBomb,
    Repeater
  };

  gameobject GetClick()
  {
    return click;
  }
  void ChangeClick(gameobject nclick)
  {
    click = nclick;
  }

  void add(std::shared_ptr<GameObject>);

  int GetTick()
  {
    return tick;
  }

  bool samerow(int y);

  bool jump(std::shared_ptr<GameObject>);

private:
  std::list<std::shared_ptr<GameObject>> objects;
  int tick;
  gameobject click;
};

#endif // !GAMEWORLD_HPP__
