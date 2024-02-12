#ifndef PEA_HPP__
#define PEA_HPP__

#include "GameObject.hpp"

class Pea : public GameObject
{
public:
    Pea(int x, int y, pGameWorld ptr);

    void Update();
    void OnClick();
};

#endif // !Pea_HPP__