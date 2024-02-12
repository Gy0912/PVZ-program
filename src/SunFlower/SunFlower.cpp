#include "SunFlower.hpp"

SunFlower::SunFlower(int X, int Y, pGameWorld pgameworld)
    : GameObject(IMGID_SUNFLOWER, X, Y, LAYER_PLANTS, 60, 80, ANIMID_IDLE_ANIM, 300, pgameworld)
{
    ChangeType(GameObject::ObjectType::Plant);
    ChangeGWPtr(pgameworld);
    firsttime = randInt(30, 600);
    existtime = 0;
}

void SunFlower::Update()
{
    existtime++;
    if (GetHp() > 0)
    {
        if ((existtime - firsttime) % 600 == 0)
        {
            std::shared_ptr<GameObject> sunfromflower = std::make_shared<SunFF>(GetX(), GetY(), GetGWptr());
            GetGWptr()->add(sunfromflower);
        }
    }
}

void SunFlower::OnClick()
{
    if (GetGWptr()->GetClick() == GameWorld::gameobject::Spade)
    {
        ChangeHp(300);
        GetGWptr()->ChangeClick(GameWorld::gameobject::None);
        existtime = 0;
    }
}
