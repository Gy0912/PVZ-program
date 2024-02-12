#include "Pea.hpp"

Pea::Pea(int X, int Y, pGameWorld ptr)
    : GameObject(IMGID_PEA, X, Y, LAYER_PROJECTILES, 28, 28, ANIMID_NO_ANIMATION, 1, ptr)
{
    ChangeType(GameObject::ObjectType::Pea);
}

void Pea::Update()
{
    if (GetHp() > 0)
    {
        MoveTo(GetX() + 8, GetY());
        if (GetX() >= WINDOW_WIDTH)
        {
            ChangeHp(1);
        }
    }
}

void Pea::OnClick() {}
