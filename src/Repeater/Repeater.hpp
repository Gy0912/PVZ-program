#ifndef REPEATER_HPP__
#define REPEATER_HPP__

#include "GameObject.hpp"

class Repeater : public GameObject
{
public:
    Repeater(int x, int y, pGameWorld ptr);

    void Update();
    void OnClick();

private:
    int shoottime;
};

#endif // !REPEATER_HPP__