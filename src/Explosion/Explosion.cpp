#include "Explosion.hpp"

Explosion::Explosion(int X, int Y, pGameWorld ptr)
    : GameObject(IMGID_EXPLOSION, X, Y, LAYER_PROJECTILES, 3 * LAWN_GRID_WIDTH, 3 * LAWN_GRID_HEIGHT, ANIMID_NO_ANIMATION, 3, ptr)
{
    ChangeType(GameObject::ObjectType::Explosion);
}

void Explosion::Update()
{
    ChangeHp(1);
}
void Explosion::OnClick() {}
