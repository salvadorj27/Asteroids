#pragma once

#ifndef SHIP_HPP
#define SHIP_HPP

// STL
#include <vector>

// Asteroids
#include "Vector2.hpp"

namespace Engine
{
    class App;
    class Ship
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
        void Render();
        void ShipRespawn();

    private:
 
        void ApplyImpulse(Math::Vector2 impulse);
        void ApplyDrag(Math::Vector2 force);

        std::vector<Engine::Math::Vector2> m_points;
        Engine::Math::Vector2 m_position;
        Engine::Math::Vector2 m_velocity;
        float m_angle;
        float m_mass;
        float m_rotation;
        float m_currentSpeed;
        App* m_parent;
        int m_second_ship;
    };
} 
#endif