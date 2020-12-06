#pragma once

#ifndef BULLET_HPP
#define BULLET_HPP


#include "GameObject.hpp"

namespace Engine
{
    class App;
    class Bullet : public GameObject
    {
        public:
            Bullet(App* parent);
            void Update(float deltaTime);
            void Render();    

        private:

            float m_lifeSpan;
            float m_currentLifeSpan;
            App* m_parent;
    };
}

#endif