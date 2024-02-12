#include "Spade.hpp"

Spade::Spade(pGameWorld ptr)
    : GameObject(IMGID_SHOVEL, 600, WINDOW_HEIGHT - 40, LAYER_UI, 50, 50, ANIMID_NO_ANIMATION, 1, ptr)
{
    ChangeType(GameObject::ObjectType::None);
    ChangeGWPtr(ptr);
}

void Spade::Update() {}
void Spade::OnClick()
{
    if (GetGWptr()->GetClick() == GameWorld::gameobject::Spade)
    {
        GetGWptr()->ChangeClick(GameWorld::gameobject::None);
    }
    else if (GetGWptr()->GetClick() == GameWorld::gameobject::None)
    {
        GetGWptr()->ChangeClick(GameWorld::gameobject::Spade);
    }
}
