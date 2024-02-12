#ifndef COOLDOWNMASK_HPP__
#define COOLDOWNMASK_HPP__

#include "GameObject.hpp"

class CooldownMask : public GameObject
{
public:
    CooldownMask(int, int, int, pGameWorld ptr);

    void Update();
    void OnClick();

private:
    int cooltime;
};

#endif // !COOLDOWNMASK_HPP__