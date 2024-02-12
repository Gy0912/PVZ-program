#include "RepeaterSeed.hpp"
#include "CooldownMask.hpp"

RepeaterSeed::RepeaterSeed(pGameWorld pgameworld)
    : GameObject(IMGID_SEED_REPEATER, 370, WINDOW_HEIGHT - 44, LAYER_UI, 50, 70, ANIMID_NO_ANIMATION, 1, pgameworld), coolingtime(0)
{
    ChangeGWPtr(pgameworld);
    ChangeType(GameObject::ObjectType::None);
}

void RepeaterSeed::Update()
{
    if (coolingtime > 0)
    {
        coolingtime--;
    }
}

void RepeaterSeed::OnClick()
{
    if (GetGWptr()->GetSun() >= 200 && coolingtime == 0 && GetGWptr()->GetClick() == GameWorld::gameobject::None)
    {
        coolingtime = 240;
        GetGWptr()->ChangeClick(GameWorld::gameobject::Repeater);
        GetGWptr()->add(std::make_shared<CooldownMask>(GetX(), GetY(), coolingtime, GetGWptr()));
        GetGWptr()->SetSun(GetGWptr()->GetSun() - 200);
    }
}
