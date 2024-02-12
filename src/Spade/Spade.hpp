#ifndef SPADE_HPP__
#define SPADE_HPP__

#include "GameObject.hpp"

class Spade : public GameObject
{
public:
    Spade(pGameWorld ptr);

    void Update();
    void OnClick();
};

#endif // !Spade_HPP__