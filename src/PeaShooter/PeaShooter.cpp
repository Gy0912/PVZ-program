#include "PeaShooter.hpp"

PeaShooter::PeaShooter(int X, int Y, pGameWorld pgameworld)
    : GameObject(IMGID_PEASHOOTER, X, Y, LAYER_PLANTS, 60, 80, ANIMID_IDLE_ANIM, 300, pgameworld)
{
    ChangeType(GameObject::ObjectType::Plant);
    ChangeGWPtr(pgameworld);
    shoottime = 0;
}

void PeaShooter::Update()
{
    if (GetHp() > 0)
    {
        if (GetGWptr()->samerow(GetY()))
        {
            if (shoottime == 0 || shoottime == 30)
            {
                shoottime = 0;
                GetGWptr()->add(std::make_shared<Pea>(GetX() + 30, GetY() + 20, GetGWptr()));
                shoottime++;
            }
        }
        if (shoottime < 30 && shoottime > 0)
        {
            shoottime++;
        }
    }
}

void PeaShooter::OnClick()
{
    if (GetGWptr()->GetClick() == GameWorld::gameobject::Spade)
    {
        ChangeHp(300);
        GetGWptr()->ChangeClick(GameWorld::gameobject::None);
    }
}
