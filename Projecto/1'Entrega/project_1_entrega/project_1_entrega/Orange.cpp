//
//  project_1_entrega - Orange.cpp
//
//#ifdef _WIN32
////define something for Windows (32-bit and 64-bit, this part is common)
//#include <GL\glut.h>
//#elif __APPLE__
//// Other kinds of Mac OS
//#include <GLUT/glut.h>
//#endif
#include "Game.h"
#include "Orange.h"
//#include "GameObject.h"

Orange::Orange() : DynamicObject(){};
Orange::~Orange(){};

void Orange::draw(){
    logger.debug("On Orange::draw()");
	glPushMatrix();
    glTranslatef(0.0f, 0.5f, 1.0f);
	glColor3f(1.0, 0.4, 0.0);
	glScalef(0.025, 0.025, 0.025);
		glPushMatrix();
		glutSolidSphere(5.0, 15.0, 10.0);
		glPopMatrix();
	glPopMatrix();
};
void Orange::update(float delta){
    
};