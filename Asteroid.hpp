#pragma once

#ifndef ASTEROID_HPP
#define ASTEROID_HPP
#include "GameObject.hpp"

#include <vector>

#include "Vector2.hpp"

namespace Engine
{   class App;
    class Asteroid : public GameObject
    {
        public:
            Asteroid(App* parent);
            void Update(float deltaTime);
        private:
            App* m_parent;
    };
} 
#endif