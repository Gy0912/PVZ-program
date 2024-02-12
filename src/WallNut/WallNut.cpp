#include "WallNut.hpp"

WallNut::WallNut(int X, int Y, pGameWorld pgameworld)
    : GameObject(IMGID_WALLNUT, X, Y, LAYER_PLANTS, 60, 80, ANIMID_IDLE_ANIM, 4000, pgameworld)
{
    ChangeType(GameObject::ObjectType::Plant);
    ChangeGWPtr(pgameworld);
    changetimes = 0;
}

void WallNut::Update()
{
    if (GetHp() < 4000 / 3 && GetHp() > 0 && changetimes == 0)
    {
        ChangeImage(IMGID_WALLNUT_CRACKED);
        changetimes++;
    }
}

void WallNut::OnClick()
{
    if (GetGWptr()->GetClick() == GameWorld::gameobject::Spade)
    {
        ChangeHp(4000);
        GetGWptr()->ChangeClick(GameWorld::gameobject::None);
    }
}
