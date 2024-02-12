#ifndef Zombie_HPP__
#define Zombie_HPP__

#include "GameObject.hpp"

class RegularZombie : public GameObject
{
public:
    RegularZombie(int x, int y, pGameWorld ptr);

    void Update();
    void OnClick();
};

class BucketHeadZombie : public GameObject
{
public:
    BucketHeadZombie(int x, int y, pGameWorld ptr);

    void Update();
    void OnClick();
};

class PoleVaultingZombie : public GameObject
{
public:
    PoleVaultingZombie(int x, int y, pGameWorld ptr);

    void Update();
    void OnClick();
};

#endif // !Zombie_HPP__