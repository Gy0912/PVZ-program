#ifndef WALLNUTSEED_HPP__
#define WALLNUTSEED_HPP__

#include "GameObject.hpp"
#include "CooldownMask.hpp"

class WallNutSeed : public GameObject
{
public:
    WallNutSeed(pGameWorld ptr);

    void Update();
    void OnClick();

private:
    int coolingtime;
};

#endif // !WALLNUTSEED_HPP__