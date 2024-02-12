#ifndef SUNFROMSKY_HPP__
#define SUNFROMSKY_HPP__

#include "GameObject.hpp"

class SunFS : public GameObject
{
public:
    SunFS(int x, pGameWorld);
    void Update();
    void OnClick();

private:
    int FallTime;
};

#endif // !SUNFROMSKY_HPP__