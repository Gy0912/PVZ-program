#include "Zombie.hpp"

RegularZombie::RegularZombie(int X, int Y, pGameWorld pgameworld)
    : GameObject(IMGID_REGULAR_ZOMBIE, X, Y, LAYER_ZOMBIES, 20, 80, ANIMID_WALK_ANIM, 200, pgameworld)
{
    ChangeType(GameObject::ObjectType::Zombie);
    ChangeGWPtr(pgameworld);
}

void RegularZombie::Update()
{
    if (GetHp() > 0)
    {
        if (GetCurrentAnimation() == ANIMID_WALK_ANIM)
        {
            MoveTo(GetX() - 1, GetY());
        }
    }
}

void RegularZombie::OnClick() {}

BucketHeadZombie::BucketHeadZombie(int X, int Y, pGameWorld pgameworld)
    : GameObject(IMGID_BUCKET_HEAD_ZOMBIE, X, Y, LAYER_ZOMBIES, 20, 80, ANIMID_WALK_ANIM, 1300, pgameworld)
{
    ChangeType(GameObject::ObjectType::Zombie);
    ChangeGWPtr(pgameworld);
}

void BucketHeadZombie::Update()
{
    if (GetHp() > 0)
    {
        if (GetHp() <= 200)
        {
            ChangeImage(IMGID_REGULAR_ZOMBIE);
        }
        if (GetCurrentAnimation() == ANIMID_WALK_ANIM)
        {
            MoveTo(GetX() - 1, GetY());
        }
    }
}

void BucketHeadZombie::OnClick() {}

PoleVaultingZombie::PoleVaultingZombie(int X, int Y, pGameWorld pgameworld)
    : GameObject(IMGID_POLE_VAULTING_ZOMBIE, X, Y, LAYER_ZOMBIES, 20, 80, ANIMID_RUN_ANIM, 340, pgameworld)
{
    ChangeType(GameObject::ObjectType::Zombie);
    ChangeGWPtr(pgameworld);
}

void PoleVaultingZombie::Update()
{
    if (GetHp() > 0)
    {
        if (GetCurrentAnimation() == ANIMID_RUN_ANIM && GetGWptr()->jump(shared_from_this()))
        {
            MoveTo(GetX() - 40, GetY());
        }
        if (GetCurrentAnimation() == ANIMID_RUN_ANIM)
        {
            MoveTo(GetX() - 2, GetY());
        }
        if (GetCurrentAnimation() == ANIMID_WALK_ANIM)
        {
            MoveTo(GetX() - 1, GetY());
        }
    }
}

void PoleVaultingZombie::OnClick() {}