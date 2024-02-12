#include "GameObject.hpp"

GameObject::GameObject(ImageID imageID, int x, int y, LayerID layer, int width, int height, AnimID animID, int Hp, pGameWorld ptr)
    : ObjectBase(imageID, x, y, layer, width, height, animID), hp(Hp), p_GameWorld(ptr) {}

int GameObject::GetHp()
{
    return hp;
}

void GameObject::ChangeHp(int hurt)
{
    hp -= hurt;
}

pGameWorld GameObject::GetGWptr()
{
    return p_GameWorld;
}

void GameObject::ChangeGWPtr(pGameWorld ptr)
{
    p_GameWorld = ptr;
}
