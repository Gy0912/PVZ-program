#ifndef WALLNUT_HPP__
#define WALLNUT_HPP__

#include "GameObject.hpp"

class WallNut : public GameObject
{
public:
    WallNut(int x, int y, pGameWorld ptr);

    void Update();
    void OnClick();

private:
    int changetimes;
};

#endif // !WALLNUT_HPP__