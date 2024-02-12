#ifndef BACKGROUND_HPP__
#define BACKGROUND_HPP__

#include "GameObject.hpp"

class Background : public GameObject
{
public:
    Background(pGameWorld ptr);

    void Update();
    void OnClick();
};

#endif // !BACKGROUND_HPP__