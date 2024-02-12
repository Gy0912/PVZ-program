#include "SunFlowerSeed.hpp"
#include "CooldownMask.hpp"

SunFlowerSeed::SunFlowerSeed(pGameWorld pgameworld)
    : GameObject(IMGID_SEED_SUNFLOWER, 130, WINDOW_HEIGHT - 44, LAYER_UI, 50, 70, ANIMID_NO_ANIMATION, 1, pgameworld), coolingtime(0)
{
    ChangeGWPtr(pgameworld);
    ChangeType(GameObject::ObjectType::None);
}

void SunFlowerSeed::Update()
{
    if (coolingtime > 0)
    {
        coolingtime--;
    }
}

void SunFlowerSeed::OnClick()
{
    if (GetGWptr()->GetSun() >= 50 && coolingtime == 0 && GetGWptr()->GetClick() == GameWorld::gameobject::None)
    {
        coolingtime = 240;
        GetGWptr()->ChangeClick(GameWorld::gameobject::SunFlower);
        GetGWptr()->add(std::make_shared<CooldownMask>(GetX(), GetY(), coolingtime, GetGWptr()));
        GetGWptr()->SetSun(GetGWptr()->GetSun() - 50);
    }
}
