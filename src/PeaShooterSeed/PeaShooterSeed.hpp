#ifndef PEASHOOTERSEED_HPP__
#define PEASHOOTERSEED_HPP__

#include "GameObject.hpp"
#include "CooldownMask.hpp"

class PeaShooterSeed : public GameObject
{
public:
    PeaShooterSeed(pGameWorld ptr);

    void Update();
    void OnClick();

private:
    int coolingtime;
};

#endif // !PEASHOOTERSEED_HPP__