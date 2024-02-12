#include "SunFromFlower.hpp"

SunFF::SunFF(int X, int Y, pGameWorld pgameworld)
    : GameObject(IMGID_SUN, X, Y, LAYER_SUN, 80, 80, ANIMID_IDLE_ANIM, 1, pgameworld)
{
    ChangeType(GameObject::ObjectType::None);
    FallTime = 12;
    ChangeGWPtr(pgameworld);
    speed = 4;
}

void SunFF::Update()
{
    FallTime--;
    if (FallTime >= 0)
    {
        MoveTo(GetX() - 1, GetY() + speed);
        speed--;
    }
    if (FallTime == -300)
    {
        ChangeHp(1);
    }
}

void SunFF::OnClick()
{
    GetGWptr()->SetSun(GetGWptr()->GetSun() + 25);
    ChangeHp(1);
}