#ifndef REPEATERSEED_HPP__
#define REPEATERSEED_HPP__

#include "GameObject.hpp"

class RepeaterSeed : public GameObject
{
public:
    RepeaterSeed(pGameWorld ptr);

    void Update();
    void OnClick();

private:
    int coolingtime;
};

#endif // !REPEATERSEED_HPP__