#include "SunFromSky.hpp"

SunFS::SunFS(int X, pGameWorld pgameworld)
    : GameObject(IMGID_SUN, X, WINDOW_HEIGHT - 1, LAYER_SUN, 80, 80, ANIMID_IDLE_ANIM, 1, pgameworld)
{
    ChangeType(GameObject::ObjectType::None);
    FallTime = randInt(63, 263);
    ChangeGWPtr(pgameworld);
}

void SunFS::Update()
{
    if (FallTime > 0)
    {
        MoveTo(GetX(), GetY() - 2);
    }
    if (FallTime == -300)
    {
        ChangeHp(1);
    }
    FallTime--;
}

void SunFS::OnClick()
{
    GetGWptr()->SetSun(GetGWptr()->GetSun() + 25);
    ChangeHp(1);
}