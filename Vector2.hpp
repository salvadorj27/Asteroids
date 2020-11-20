#pragma once
#include <iostream>

namespace Engine
{
    namespace Math
    {
        struct Vector2
        {
  
            static Vector2 Origin;

   
            Vector2();
            Vector2(float, float);
            Vector2(float);

  
            float Length() const;
            float SquaredLength() const;
            float Normalize();

            static constexpr float PI = 3.141592653;
            float x;
            float y;
            float length;
        };
    } // namespace Math
} // namespace Engine