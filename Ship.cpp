#include "Ship.hpp"
#include "App.hpp"
//#include "Wrap.hpp"
#include <gl\GL.h>
#include <cmath>
#include "Bullet.hpp"

namespace Engine
{
    const float MAX_VELOCITY = 500.0F;
    const float THRUST = 15.0F;
    const float DRAG_FORCE = 0.999F;
    const float ANGLE_OFFSET = 90.0F;
    const float BULLET_SPEED = 250;

     Ship::Ship(App* parent)
        : GameObject(1.0f, 0.0f, 250.0f)
        , m_parent(parent) 
    {        
        std::cout << "Construction of ship\n";
        ChangeShip();
    }

    Ship::Ship(App* parent, float _x, float _y)
        : GameObject(1.0f, 0.0f, 250.0f)
        , m_parent(parent)
    {
        m_position = Math::Vector2(_x, _y);
        std::cout << "Construction of ship\n";
        ChangeShip();
    }

    Ship::~Ship()
    {
        std::cout << "Destruction of ship\n";
    }

    void Ship::MoveUp()
    {
        ApplyImpulse(Math::Vector2(THRUST), m_angle + ANGLE_OFFSET);
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
        GameObject::Update(m_parent, deltaTime);
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

     Bullet* Ship::Shoot()
    {
        float shootingAngle = m_angle + ANGLE_OFFSET;
        float bulletPx = m_points[0].x * cosf(shootingAngle * ( Engine::Math::Vector2::PI / 180));
        float bulletPy = m_points[0].y * sinf(shootingAngle * ( Engine::Math::Vector2::PI / 180));

        Bullet* bullet = new Bullet(m_parent);        
        bullet->Teleport(m_position.x + bulletPx, m_position.y + bulletPy);
        bullet->ApplyImpulse(Math::Vector2(m_currentSpeed + BULLET_SPEED), shootingAngle);

        return bullet;
    }

}