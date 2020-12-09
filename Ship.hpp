#pragma once

#ifndef SHIP_HPP
#define SHIP_HPP


#include <vector>

#include "GameObject.hpp"
#include "Vector2.hpp"

namespace Engine
{
    class App;
    class Bullet;
    class Ship : public GameObject
    {
    public:
    
        Ship(App* parent);
        Ship(App* parent, float, float);
        ~Ship();

        void ChangeShip();
        void MoveUp();
        void RotateLeft(float deltaTime);
        void RotateRight(float deltaTime);
        void Update(float deltaTime);
        void ShipRespawn();
        void RespawnShip();
        Bullet* Shoot();

    private:
        void ApplyDrag(Math::Vector2 force);
        float m_currentSpeed;
        App* m_parent;
        int m_second_ship;
    };
} 
#endif