#include "CherryBombSeed.hpp"

CherryBombSeed::CherryBombSeed(pGameWorld pgameworld)
    : GameObject(IMGID_SEED_CHERRY_BOMB, 310, WINDOW_HEIGHT - 44, LAYER_UI, 50, 70, ANIMID_NO_ANIMATION, 1, pgameworld), coolingtime(0)
{
    ChangeGWPtr(pgameworld);
    ChangeType(GameObject::ObjectType::None);
}

void CherryBombSeed::Update()
{
    if (coolingtime > 0)
    {
        coolingtime--;
    }
}

void CherryBombSeed::OnClick()
{
    if (GetGWptr()->GetSun() >= 150 && coolingtime == 0 && GetGWptr()->GetClick() == GameWorld::gameobject::None)
    {
        coolingtime = 1200;
        GetGWptr()->ChangeClick(GameWorld::gameobject::CherryBomb);
        GetGWptr()->add(std::make_shared<CooldownMask>(GetX(), GetY(), coolingtime, GetGWptr()));
        GetGWptr()->SetSun(GetGWptr()->GetSun() - 150);
    }
}
