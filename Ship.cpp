#pragma once
#include <iostream>
#include <SDL2/SDL_opengl.h>
#include "Ship.hpp"
#ifndef Shipp_HPP
#define Ship_HPP

namespace Engine {

    void ship::ship_render()
    {
	
	    
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

	    
    };

}
#endif // _SHIP_H_