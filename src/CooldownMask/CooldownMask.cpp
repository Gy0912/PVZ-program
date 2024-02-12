#include "CooldownMask.hpp"

CooldownMask::CooldownMask(int X, int Y, int cd, pGameWorld ptr)
    : GameObject(IMGID_COOLDOWN_MASK, X, Y, LAYER_COOLDOWN_MASK, 50, 70, ANIMID_NO_ANIMATION, 1, ptr)
{
    cooltime = cd;
    ChangeType(GameObject::ObjectType::None);
}

void CooldownMask::Update()
{
    if (cooltime == 0)
    {
        ChangeHp(1);
    }
    cooltime--;
}

void CooldownMask::OnClick() {}
