#include "demo_utils.h"


#include "GL/glew.h"



void demo::drawTestTriangle()
{
	// immediate mode coloured triangle... DO NOT USE IMMEDIATE MODE!!!!
	glBegin(GL_TRIANGLES);
		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex3f(-0.4f, -0.5f, -0.5f);
		glColor3f(0.0f, 1.0f, 0.0f);
		glVertex3f(0.4f, -0.5f, 0.0f);
		glColor3f(0.0f, 0.0f, 1.0f);
		glVertex3f(0.0f, 0.5f, 1.0f);
	glEnd();
}

void demo::drawTestRect()
{
	// immediate mode coloured rectangle... DO NOT USE IMMEDIATE MODE!!!!
	glBegin(GL_TRIANGLE_STRIP);
		glColor3f(0.0f, 0.0f, 1.0f);
		glVertex3f(-0.5f, -0.5f, 0.0f);
		glColor3f(1.0f, 0.0f, 1.0f);
		glVertex3f( 0.5f, -0.5f, 0.0f);
		glColor3f(0.0f, 1.0f, 1.0f);
		glVertex3f(-0.5f,  0.5f, 0.0f);
		glColor3f(1.0f, 1.0f, 1.0f);
		glVertex3f( 0.5f,  0.5f, 0.0f);
	glEnd();
}

void demo::drawTestAxes()
{
	// immediate mode axes; r = x, g = y, b = z... DO NOT USE IMMEDIATE MODE!!!!
	glBegin(GL_LINES);
		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex3f(1.0f, 0.0f, 0.0f);
		glVertex3f(0.0f, 0.0f, 0.0f);
		glColor3f(0.0f, 1.0f, 0.0f);
		glVertex3f(0.0f, 1.0f, 0.0f);
		glVertex3f(0.0f, 0.0f, 0.0f);
		glColor3f(0.0f, 0.0f, 1.0f);
		glVertex3f(0.0f, 0.0f, 1.0f);
		glVertex3f(0.0f, 0.0f, 0.0f);
	glEnd();
}

