#include "WallNutSeed.hpp"

WallNutSeed::WallNutSeed(pGameWorld pgameworld)
    : GameObject(IMGID_SEED_WALLNUT, 250, WINDOW_HEIGHT - 44, LAYER_UI, 50, 70, ANIMID_NO_ANIMATION, 1, pgameworld), coolingtime(0)
{
    ChangeGWPtr(pgameworld);
    ChangeType(GameObject::ObjectType::None);
}

void WallNutSeed::Update()
{
    if (coolingtime > 0)
    {
        coolingtime--;
    }
}

void WallNutSeed::OnClick()
{
    if (GetGWptr()->GetSun() >= 50 && coolingtime == 0 && GetGWptr()->GetClick() == GameWorld::gameobject::None)
    {
        coolingtime = 900;
        GetGWptr()->ChangeClick(GameWorld::gameobject::WallNut);
        GetGWptr()->add(std::make_shared<CooldownMask>(GetX(), GetY(), coolingtime, GetGWptr()));
        GetGWptr()->SetSun(GetGWptr()->GetSun() - 50);
    }
}