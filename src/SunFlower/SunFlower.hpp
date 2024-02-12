#ifndef SUNFLOWER_HPP__
#define SUNFLOWER_HPP__

#include "GameObject.hpp"
#include "SunFromFlower.hpp"

class SunFlower : public GameObject
{
public:
    SunFlower(int x, int y, pGameWorld ptr);

    void Update();
    void OnClick();

private:
    int firsttime;
    int existtime;
};

#endif // !SUNFLOWER_HPP__