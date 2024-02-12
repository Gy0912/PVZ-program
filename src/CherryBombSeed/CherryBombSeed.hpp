#ifndef CHERRYBOMBSEED_HPP__
#define CHERRYBOMBSEED_HPP__

#include "GameObject.hpp"
#include "CooldownMask.hpp"

class CherryBombSeed : public GameObject
{
public:
    CherryBombSeed(pGameWorld ptr);

    void Update();
    void OnClick();

private:
    int coolingtime;
};

#endif // !CHERRYBOMBSEED_HPP__