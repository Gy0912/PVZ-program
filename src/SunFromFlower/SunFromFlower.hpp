#ifndef SUNFROMFLOWER_HPP__
#define SUNFROMFLOWER_HPP__

#include "GameObject.hpp"

class SunFF : public GameObject
{
public:
    SunFF(int, int, pGameWorld);
    void Update();
    void OnClick();

private:
    int FallTime;
    int speed;
};

#endif // !SUN_HPP__