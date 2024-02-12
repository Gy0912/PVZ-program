#include "Background.hpp"
#include "GameWorld.hpp"

Background::Background(pGameWorld ptr)
    : GameObject(IMGID_BACKGROUND, WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2, LAYER_BACKGROUND, WINDOW_WIDTH, WINDOW_HEIGHT, ANIMID_NO_ANIMATION, 1, ptr)
{
    ChangeType(GameObject::ObjectType::None);
}

void Background::Update() {}
void Background::OnClick() {}
