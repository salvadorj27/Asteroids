#include "Ship.hpp"
#include "App.hpp"
#include "Wrap.hpp"
#include <gl\GL.h>

#include <iostream>
#include <cmath>

namespace Engine
{
    
    Ship::Ship(App* parent)
        : m_position(Math::Vector2::Origin)   
        , m_velocity(Math::Vector2::Origin)  
        , m_angle(0.0f)     
        , m_rotation(250.0f)
        , m_mass(1.0f)
        , m_parent(parent) 
    {        
        std::cout << "Construction of ship\n";
        ChangeShip();
    }

    Ship::Ship(App* parent, float _x, float _y)
        : m_position(_x, _y)    
        , m_velocity(Math::Vector2::Origin)  
        , m_angle(0.0f)     
        , m_rotation(250.0f)
        , m_mass(1.0f)    
        , m_parent(parent)
    {
        std::cout << "Construction of ship\n";
    }

    Ship::~Ship()
    {
        std::cout << "Destruction of ship\n";
    }

    void Ship::MoveUp()
    {
        ApplyImpulse(Math::Vector2(THRUST));
    }

    void Ship::RotateLeft( float deltaTime )
    {        
        m_angle += m_rotation * deltaTime;
    }

    void Ship::RotateRight( float deltaTime )
    {        
        m_angle -= m_rotation * deltaTime;
    }

    void Ship::ApplyDrag(Math::Vector2 force)
    {
        m_velocity.x *= force.x;
        m_velocity.y *= force.y;
    }

    void Ship::ApplyImpulse(Math::Vector2 impulse)
    {
        if(m_mass > 0)
        {
            m_velocity.x += (impulse.x / m_mass) * cosf((m_angle + ANGLE_OFFSET) * (Engine::Math::Vector2::PI / 180));
            m_velocity.y += (impulse.y / m_mass) * sinf((m_angle + ANGLE_OFFSET) * (Engine::Math::Vector2::PI / 180));
        }
    }

    void Ship::Update(float deltaTime)
    {
        
        float speed = 
            std::fabs(m_velocity.Length());

        
        if(speed > MAX_VELOCITY)
        {
            m_velocity.x = (m_velocity.x / speed) * MAX_VELOCITY;
            m_velocity.y = (m_velocity.y / speed) * MAX_VELOCITY;
        }

        
        m_currentSpeed = speed;
        m_position.x += m_velocity.x * deltaTime;
        m_position.y += m_velocity.y * deltaTime;

        
        ApplyDrag(Math::Vector2(DRAG_FORCE));

        
        float halfWidth = m_parent->GetWidth() / 2.0f;
        float halfHeight = m_parent->GetHeight() / 2.0f;

        float worldMinX = -halfWidth;
        float worldMaxX = halfWidth;

        float worldMinY = -halfHeight;
        float worldMaxY = halfHeight;

        m_position.x = wrap(m_position.x, worldMinX, worldMaxX);
        m_position.y = wrap(m_position.y, worldMinY, worldMaxY);
    }

    void Ship::ChangeShip()
    {
        m_second_ship = ++m_second_ship % 2;
        m_points.clear();

        switch(m_second_ship)
        {
        case 1:
            m_points.push_back(Math::Vector2(12.0f, 0.0f));
            m_points.push_back(Math::Vector2(12.0f, 51.0f));
            m_points.push_back(Math::Vector2(39.0f, -9.0f));
            m_points.push_back(Math::Vector2(39.0f, -24.0f));
            m_points.push_back(Math::Vector2(12.0f, -36.0f));
            m_points.push_back(Math::Vector2(-12.0f, -36.0f));
            m_points.push_back(Math::Vector2(-39.0f, -24.0f));
            m_points.push_back(Math::Vector2(-39.0f, -9.0f));
            m_points.push_back(Math::Vector2(-12.0f, 51.0f));
            m_points.push_back(Math::Vector2(-12.0f, 0.0f));
            m_points.push_back(Math::Vector2(-6.0f, 0.0f));
            m_points.push_back(Math::Vector2(-6.0f, 6.0f));
            m_points.push_back(Math::Vector2(-3.0f, 4.5f));
            m_points.push_back(Math::Vector2(3.0f, 4.5f));
            m_points.push_back(Math::Vector2(6.0f, 6.0f));
            m_points.push_back(Math::Vector2(6.0f, 0.0f));
            break;
        default:
             m_points.push_back(Math::Vector2(9.0f, 0.0f));
            m_points.push_back(Math::Vector2(18.0f, 9.0f));
            m_points.push_back(Math::Vector2(18.0f, 36.0f));
            m_points.push_back(Math::Vector2(54.0f, -45.0f));
            m_points.push_back(Math::Vector2(18.0f, -36.0f));
            m_points.push_back(Math::Vector2(18.0f, -45.0f));
            m_points.push_back(Math::Vector2(0.0f, -36.0f));
            m_points.push_back(Math::Vector2(-18.0f, -45.0f));
            m_points.push_back(Math::Vector2(-18.0f, -36.0f));
            m_points.push_back(Math::Vector2(-54.0f, -45.0f));
            m_points.push_back(Math::Vector2(-18.0f, 36.0f));
            m_points.push_back(Math::Vector2(-18.0f, 9.0f));
            m_points.push_back(Math::Vector2(-9.0f, 0.0f));
            m_points.push_back(Math::Vector2(0.0f, 18.0f));
            break;
        }
    }

    void Ship::Render()
    {
        glLoadIdentity();
        glTranslatef(m_position.x, m_position.y, 0.0);
        glRotatef(m_angle, 0.0f, 0.0f, 1.0f);
        glBegin(GL_LINE_LOOP);
            std::vector<Math::Vector2>::iterator it = m_points.begin();
            for(; it != m_points.end(); ++it)
            {
                glVertex2f((*it).x, (*it).y);
            }
        glEnd();
    }
    void Ship::ShipRespawn()
    {
        m_position.x = 0.0f;
        m_position.y = 0.0f;
        m_velocity.x = 0.0f;
        m_velocity.y = 0.0f;
        m_angle = 0.0f;
        
        glLoadIdentity();
        glTranslatef(m_position.x, m_position.y, 0.0);
        glRotatef(m_angle, 0.0f, 0.0f, 1.0f);
        glBegin(GL_LINE_LOOP);
    }

}