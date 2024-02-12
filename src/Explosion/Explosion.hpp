#ifndef EXPLOSION_HPP__
#define EXPLOSION_HPP__

#include "GameObject.hpp"

class Explosion : public GameObject
{
public:
    Explosion(int x, int y, pGameWorld ptr);

    void Update();
    void OnClick();
};

#endif // !Explosion_HPP__