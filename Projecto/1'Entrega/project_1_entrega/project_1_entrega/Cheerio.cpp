//
//  project_1_entrega - Cheerio.cpp
//
#ifdef _WIN32
//define something for Windows (32-bit and 64-bit, this part is common)
#include <GL\glut.h>
#elif __APPLE__
// Other kinds of Mac OS
#include <GLUT/glut.h>
#endif
#include "Game.h"
#include "Cheerio.h"
#include <iostream>

Cheerio::Cheerio(){};
Cheerio::~Cheerio(){};
void Cheerio::draw(){
    glPushMatrix();
    glColor3f(1.0f, 0.5f, 0.0f);
    glutSolidTorus(0.007f, 0.02f, 10.0, 100.0f);
    glPopMatrix();
};
