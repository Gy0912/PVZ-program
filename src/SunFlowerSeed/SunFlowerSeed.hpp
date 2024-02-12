#ifndef SUNFLOWERSEED_HPP__
#define SUNFLOWERSEED_HPP__

#include "GameObject.hpp"

class SunFlowerSeed : public GameObject
{
public:
    SunFlowerSeed(pGameWorld ptr);

    void Update();
    void OnClick();

private:
    int coolingtime;
};

#endif // !SUNFLOWERSEED_HPP__