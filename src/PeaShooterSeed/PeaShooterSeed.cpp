#include "PeaShooterSeed.hpp"

PeaShooterSeed::PeaShooterSeed(pGameWorld pgameworld)
    : GameObject(IMGID_SEED_PEASHOOTER, 190, WINDOW_HEIGHT - 44, LAYER_UI, 50, 70, ANIMID_NO_ANIMATION, 1, pgameworld), coolingtime(0)
{
    ChangeGWPtr(pgameworld);
    ChangeType(GameObject::ObjectType::None);
}

void PeaShooterSeed::Update()
{
    if (coolingtime > 0)
    {
        coolingtime--;
    }
}

void PeaShooterSeed::OnClick()
{
    if (GetGWptr()->GetSun() >= 100 && coolingtime == 0 && GetGWptr()->GetClick() == GameWorld::gameobject::None)
    {
        coolingtime = 240;
        GetGWptr()->ChangeClick(GameWorld::gameobject::PeaShooter);
        GetGWptr()->add(std::make_shared<CooldownMask>(GetX(), GetY(), coolingtime, GetGWptr()));
        GetGWptr()->SetSun(GetGWptr()->GetSun() - 100);
    }
}
