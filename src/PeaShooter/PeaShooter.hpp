#ifndef PEASHOOTER_HPP__
#define PEASHOOTER_HPP__

#include "GameObject.hpp"
#include "Zombie.hpp"
#include "Pea.hpp"

class PeaShooter : public GameObject
{
public:
    PeaShooter(int x, int y, pGameWorld ptr);

    void Update();
    void OnClick();

private:
    int shoottime;
};

#endif // !PeaShooter_HPP__