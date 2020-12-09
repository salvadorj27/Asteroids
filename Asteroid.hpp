#pragma once
#ifndef ASTEROID_HPP
#define ASTEROID_HPP
#include "GameObject.hpp"

#include <vector>

#include "Vector2.hpp"

namespace Engine
{   
    class App;
    class Asteroid : public GameObject
    {
    public:
        struct AsteroidSize
        {
            enum Size
            {
                BIG = 0,
                MEDIUM = 1,
                SMALL = 2
            };
        };
        Asteroid(AsteroidSize::Size size, App *parent);
        void Update(float deltaTime);
        inline AsteroidSize::Size GetSize() { return m_size; }

        private:
            App* m_parent;
            AsteroidSize::Size m_size;
    };
} 
#endif