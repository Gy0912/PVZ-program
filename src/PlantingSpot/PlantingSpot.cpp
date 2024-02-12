#include "PlantingSpot.hpp"

PlantingSpot::PlantingSpot(int X, int Y, pGameWorld pgameworld)
    : GameObject(IMGID_NONE, X, Y, LAYER_UI, 60, 80, ANIMID_NO_ANIMATION, 1, pgameworld)
{
    ChangeType(GameObject::ObjectType::None);
    ChangeGWPtr(pgameworld);
}

void PlantingSpot::Update() {}

void PlantingSpot::OnClick()
{
    switch (GetGWptr()->GetClick())
    {
    case GameWorld::gameobject::None:
        break;
    case GameWorld::gameobject::SunFlower:
        GetGWptr()->add(std::make_shared<SunFlower>(GetX(), GetY(), GetGWptr()));
        GetGWptr()->ChangeClick(GameWorld::gameobject::None);
        break;
    case GameWorld::gameobject::PeaShooter:
        GetGWptr()->add(std::make_shared<PeaShooter>(GetX(), GetY(), GetGWptr()));
        GetGWptr()->ChangeClick(GameWorld::gameobject::None);
        break;
    case GameWorld::gameobject::WallNut:
        GetGWptr()->add(std::make_shared<WallNut>(GetX(), GetY(), GetGWptr()));
        GetGWptr()->ChangeClick(GameWorld::gameobject::None);
        break;
    case GameWorld::gameobject::CherryBomb:
        GetGWptr()->add(std::make_shared<CherryBomb>(GetX(), GetY(), GetGWptr()));
        GetGWptr()->ChangeClick(GameWorld::gameobject::None);
        break;
    case GameWorld::gameobject::Repeater:
        GetGWptr()->add(std::make_shared<Repeater>(GetX(), GetY(), GetGWptr()));
        GetGWptr()->ChangeClick(GameWorld::gameobject::None);
        break;
    }
}