#ifndef PLANTINGSPOT_HPP__
#define PLANTINGSPOT_HPP__

#include "GameObject.hpp"
#include "SunFlower.hpp"
#include "PeaShooter.hpp"
#include "Repeater.hpp"
#include "CherryBomb.hpp"
#include "WallNut.hpp"

class PlantingSpot : public GameObject
{
public:
    PlantingSpot(int x, int y, pGameWorld ptr);

    void Update();
    void OnClick();
};

#endif // !PLANTINGSPOT_HPP__