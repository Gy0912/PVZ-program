#include "CherryBomb.hpp"

CherryBomb::CherryBomb(int X, int Y, pGameWorld pgameworld)
    : GameObject(IMGID_CHERRY_BOMB, X, Y, LAYER_PLANTS, 60, 80, ANIMID_IDLE_ANIM, 4000, pgameworld)
{
    ChangeType(GameObject::ObjectType::Plant);
    ChangeGWPtr(pgameworld);
    lifetime = 15;
}

void CherryBomb::Update()
{
    if (GetHp() > 0)
    {
        lifetime--;
        if (lifetime == 0)
        {
            lifetime = 15;
            ChangeHp(4000);
            GetGWptr()->add(std::make_shared<Explosion>(GetX(), GetY(), GetGWptr()));
        }
    }
}

void CherryBomb::OnClick()
{
    if (GetGWptr()->GetClick() == GameWorld::gameobject::Spade)
    {
        ChangeHp(4000);
        GetGWptr()->ChangeClick(GameWorld::gameobject::None);
    }
}
