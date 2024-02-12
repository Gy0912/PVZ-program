#include "GameWorld.hpp"

GameWorld::GameWorld() {}

GameWorld::~GameWorld() {}

void GameWorld::Init()
{
  // YOUR CODE HERE
  objects.emplace_back(std::make_shared<Background>(shared_from_this()));
  objects.emplace_back(std::make_shared<SunFlowerSeed>(shared_from_this()));
  objects.emplace_back(std::make_shared<PeaShooterSeed>(shared_from_this()));
  objects.emplace_back(std::make_shared<WallNutSeed>(shared_from_this()));
  objects.emplace_back(std::make_shared<CherryBombSeed>(shared_from_this()));
  objects.emplace_back(std::make_shared<RepeaterSeed>(shared_from_this()));
  objects.emplace_back(std::make_shared<Spade>(shared_from_this()));
  for (int X = FIRST_COL_CENTER; X <= FIRST_COL_CENTER + LAWN_GRID_WIDTH * (GAME_COLS - 1); X += LAWN_GRID_WIDTH)
  {
    for (int Y = FIRST_ROW_CENTER; Y <= FIRST_ROW_CENTER + LAWN_GRID_HEIGHT * (GAME_ROWS - 1); Y += LAWN_GRID_HEIGHT)
    {
      objects.emplace_back(std::make_shared<PlantingSpot>(X, Y, shared_from_this()));
    }
  }
  SetWave(0);
  SetSun(50);
  tick = 0;
  click = GameWorld::gameobject::None;
}

LevelStatus GameWorld::Update()
{
  // YOUR CODE HERE
  tick++;

  if ((tick - 180) % 300 == 0)
  {
    int X = randInt(75, WINDOW_WIDTH - 75);
    objects.emplace_back(std::make_shared<SunFS>(X, shared_from_this()));
  }

  if (tick == 1200 && GetWave() == 0)
  {
    SetWave(1);
    tick = 0;
    int X = randInt(WINDOW_WIDTH - 40, WINDOW_WIDTH - 1);
    int Y = FIRST_ROW_CENTER + LAWN_GRID_HEIGHT * randInt(0, 4);
    objects.emplace_back(std::make_shared<RegularZombie>(X, Y, shared_from_this()));
  }

  if (GetWave() >= 1 && tick == std::max(150, 600 - 20 * GetWave()))
  {
    SetWave(GetWave() + 1);
    tick = 0;
    int rz = 20;
    int pvz = 2 * std::max(GetWave() - 8, 0);
    int bhz = 3 * std::max(GetWave() - 15, 0);
    for (int n = 0; n < floor((15 + GetWave()) / 10); ++n)
    {
      int X = randInt(WINDOW_WIDTH - 40, WINDOW_WIDTH - 1);
      int Y = FIRST_ROW_CENTER + LAWN_GRID_HEIGHT * randInt(0, 4);
      int real = randInt(1, rz + pvz + bhz);
      if (real <= rz)
      {
        objects.emplace_back(std::make_shared<RegularZombie>(X, Y, shared_from_this()));
      }
      else if (real > rz && real <= rz + pvz)
      {
        objects.emplace_back(std::make_shared<PoleVaultingZombie>(X, Y, shared_from_this()));
      }
      else if (real > rz + pvz && real <= rz + pvz + bhz)
      {
        objects.emplace_back(std::make_shared<BucketHeadZombie>(X, Y, shared_from_this()));
      }
    }
  }

  for (auto it = objects.begin(); it != objects.end(); ++it)
  {
    (*it)->Update();
  }

  for (auto object = objects.begin(); object != objects.end(); ++object)
  {
    if ((*object)->GetType() == GameObject::ObjectType::Zombie)
    {
      for (auto other = objects.begin(); other != objects.end(); ++other)
      {
        if ((*other)->GetType() == GameObject::ObjectType::Plant && (*object)->GetY() == (*other)->GetY() && (*object)->GetX() - (*other)->GetX() <= (*object)->GetWidth() / 2 + (*other)->GetWidth() / 2 && (*other)->GetX() - (*object)->GetX() <= (*object)->GetWidth() / 2 + (*other)->GetWidth() / 2)
        {
          (*other)->ChangeHp(3);
          if ((*object)->GetCurrentAnimation() == ANIMID_WALK_ANIM)
          {
            (*object)->PlayAnimation(ANIMID_EAT_ANIM);
            break;
          }
          if ((*object)->GetCurrentAnimation() == ANIMID_RUN_ANIM)
          {
            (*object)->PlayAnimation(ANIMID_JUMP_ANIM);
            break;
          }
          if ((*object)->GetCurrentAnimation() == ANIMID_EAT_ANIM && (*other)->GetHp() <= 0)
          {
            (*object)->PlayAnimation(ANIMID_WALK_ANIM);
            break;
          }
        }
        if ((*other)->GetType() == GameObject::ObjectType::Explosion && (*object)->GetY() - (*other)->GetY() <= (*object)->GetHeight() / 2 + (*other)->GetHeight() / 2 && (*other)->GetY() - (*object)->GetY() <= (*object)->GetHeight() / 2 + (*other)->GetHeight() / 2 && (*object)->GetX() - (*other)->GetX() <= (*object)->GetWidth() / 2 + (*other)->GetWidth() / 2 && (*other)->GetX() - (*object)->GetX() <= (*object)->GetWidth() / 2 + (*other)->GetWidth() / 2)
        {
          (*object)->ChangeHp((*object)->GetHp());
        }
        if ((*other)->GetType() == GameObject::ObjectType::Pea && (*object)->GetY() + 20 == (*other)->GetY() && (*object)->GetX() - (*other)->GetX() <= (*object)->GetWidth() / 2 + (*other)->GetWidth() / 2 && (*other)->GetX() - (*object)->GetX() <= (*object)->GetWidth() / 2 + (*other)->GetWidth() / 2)
        {
          (*object)->ChangeHp(20);
          (*other)->ChangeHp(1);
        }
      }
    }
  }

  for (auto it = objects.begin(); it != objects.end();)
  {
    if ((*it)->GetHp() <= 0)
    {
      it = objects.erase(it);
    }
    else
    {
      it++;
    }
  }

  for (auto it = objects.begin(); it != objects.end(); ++it)
  {
    if ((*it)->GetType() == GameObject::ObjectType::Zombie && (*it)->GetX() < 0)
    {
      return LevelStatus::LOSING;
    }
  }

  return LevelStatus::ONGOING;
}

void GameWorld::CleanUp()
{
  // YOUR CODE HERE
  objects.clear();
}

void GameWorld::add(std::shared_ptr<GameObject> obj)
{
  objects.emplace_back(obj);
}

bool GameWorld::samerow(int Y)
{
  for (auto it = objects.begin(); it != objects.end(); ++it)
  {
    if ((*it)->GetType() == GameObject::ObjectType::Zombie && (*it)->GetY() == Y)
    {
      return true;
    }
  }
  return false;
}

bool GameWorld::jump(std::shared_ptr<GameObject> other)
{
  for (auto it = objects.begin(); it != objects.end(); ++it)
  {
    if (other->GetType() == GameObject::ObjectType::Plant && (*it)->GetY() == other->GetY() && other->GetX() - 40 == (*it)->GetX())
    {
      return true;
    }
  }
}