#ifndef GAMEOBJECT_HPP__
#define GAMEOBJECT_HPP__

#include <memory>
#include "ObjectBase.hpp"
#include "utils.hpp"

// Declares the class name GameWorld so that its pointers can be used.
class GameWorld;
using pGameWorld = std::shared_ptr<GameWorld>;

class GameObject : public ObjectBase, public std::enable_shared_from_this<GameObject>
{
public:
  using std::enable_shared_from_this<GameObject>::shared_from_this; // Use shared_from_this() instead of "this".
  GameObject(ImageID imageID, int x, int y, LayerID layer, int width, int height, AnimID animID, int hp, pGameWorld ptr);

  virtual void Update() = 0;
  virtual void OnClick() = 0;

  int GetHp();
  void ChangeHp(int HP);

  pGameWorld GetGWptr();
  void ChangeGWPtr(pGameWorld ptr);

  enum class ObjectType
  {
    None,
    Plant,
    Zombie,
    Pea,
    Explosion
  };

  ObjectType GetType()
  {
    return type;
  }

  void ChangeType(ObjectType Type)
  {
    type = Type;
  }

private:
  int hp;
  pGameWorld p_GameWorld;
  ObjectType type;
};

#include "GameWorld.hpp"

#endif // !GAMEOBJECT_HPP__
