#ifndef CHERRYBOMB_HPP__
#define CHERRYBOMB_HPP__

#include "GameObject.hpp"
#include "Explosion.hpp"

class CherryBomb : public GameObject
{
public:
    CherryBomb(int x, int y, pGameWorld ptr);

    void Update();
    void OnClick();

private:
    int lifetime;
};

#endif // !CHERRYBOMB_HPP__