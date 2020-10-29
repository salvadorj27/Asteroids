#include "Ship.hpp"

#include <gl\GL.h>
#include <iostream>

namespace Engine
{
    inline float wrap(float x, float min, float max)
    {
        if(x < min) return max - (min - x);
        if(x > max) return min + (x - max);
        return x;
    }

    Ship::Ship()
        : m_position(Math::Vector2::Origin)
    {
        std::cout << "Construction of ship\n";
    }

    Ship::Ship(float _x, float _y)
        : m_position(_x, _y)
    {
        std::cout << "Construction of ship\n";
    }

    Ship::~Ship()
    {
        std::cout << "Destruction of ship\n";
    }

    void Ship::Move(float _x, float _y)
    {
        float x = m_position.x + _x;
        float y = m_position.y + _y;

        // TODO: RR: Move this OUT!
        float width = 1136.0f;
        float height = 640.0f;

        float min_width = -width / 2.0f;
        float max_width = width / 2.0f;

        float min_height = -height / 2.0f;
        float max_height = height / 2.0f;

        m_position.x = wrap(x, min_width, max_width);
        m_position.y = wrap(y, min_height, max_height);
    }

    void Ship::Render()
    {
        glLoadIdentity();

        glTranslatef(m_position.x, m_position.y, 0.0);
	
	    
		// glBegin(GL_QUADS);		
		// 	glVertex2f(50.0, 50.0);
        //  glVertex2f(50.0, -50.0);
        //  glVertex2f(-50.0, -50.0);
        //  glVertex2f(-50.0, 50.0);	
		// glEnd();

		// glBegin(GL_TRIANGLES);
		// 	glVertex3f(-50.0, -50.0, 0.0);
		// 	glVertex3f( 0.0,  50.0, 0.0);
		// 	glVertex3f( 50.0, -50.0, 0.0);
		// glEnd();

		// glBegin(GL_LINE_LOOP);
		// 	glVertex3f(-50.0, -50.0, 0.0);
		// 	glVertex3f( 0.0,  50.0, 0.0);
		// 	glVertex3f( 50.0, -50.0, 0.0);
		// glEnd();

		// glBegin(GL_LINE_LOOP);
            // glVertex2f(50.0, 50.0);
            // glVertex2f(50.0, -50.0);
            // glVertex2f(-50.0, -50.0);
            // glVertex2f(-50.0, 50.0);			
		// glEnd();

		glBegin(GL_LINE_LOOP);
			glVertex2f(12.0, 0.0);
			glVertex2f(12.0, 51.0);
			glVertex2f(39.0, -9.0);
			glVertex2f(39.0, -24.0);
			glVertex2f(12.0, -36.0);
			glVertex2f(-12.0, -36.0);
			glVertex2f(-39.0, -24.0);
			glVertex2f(-39.0, -9.0);
			glVertex2f(-12.0, 51.0);
			glVertex2f(-12.0, 0.0);
			glVertex2f(-6.0, 0.0);
			glVertex2f(-6.0, 6.0);
			glVertex2f(-3.0, 4.5);
			glVertex2f(3.0, 4.5);
			glVertex2f(6.0, 6.0);
			glVertex2f(6.0, 0.0);
		glEnd(); 

	    
    }

}