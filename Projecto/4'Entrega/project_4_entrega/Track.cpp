//
//  project_1_entrega - Track.cpp
//
#include "Game.h"
#include "Track.h"

Track::Track() : StaticObject(){};
Track::~Track(){};

void Track::drawV1(){
    // draw cube with 1unit as size
    glPushMatrix();
    
    if(COLISION_SPHERE){
        glColor3f(1.0f, 1.0f, 1.0f);
        glutWireSphere(getRadius(), 10, 10);
    }
    
    if(glIsEnabled(GL_LIGHTING))
        material(amb, diffuse, specular, &shine);
    glColor3f(0.55f, 0.35f, 0.05f);
    
    glBegin(GL_POLYGON);
    glVertex3f(-1.0, -1.0, 1.0);
    glVertex3f(1.0, -1.0, 1.0);
    glVertex3f(1.0, 1.0, 1.0);
    glVertex3f(-1.0, 1.0, 1.0);
    glEnd();
    
    glBegin(GL_POLYGON);
    glVertex3f(-1.0, 1.0, 1.0);
    glVertex3f(1.0, 1.0, 1.0);
    glVertex3f(1.0, 1.0, -1.0);
    glVertex3f(-1.0, -1.0, 1.0);
    glEnd();
    
    glBegin(GL_POLYGON);
    glVertex3f(-1.0, 1.0, -1.0);
    glVertex3f(1.0, 1.0, -1.0);
    glVertex3f(1.0, -1.0, -1.0);
    glVertex3f(-1.0, -1.0, -1.0);
    glEnd();
    
    glBegin(GL_POLYGON);
    glVertex3f(-1.0, -1.0, -1.0);
    glVertex3f(1.0, -1.0, -1.0);
    glVertex3f(1.0, -1.0, 1.0);
    glVertex3f(-1.0, -1.0, 1.0);
    glEnd();
    
    glBegin(GL_POLYGON);
    glVertex3f(1.0, -1.0, 1.0);
    glVertex3f(1.0, -1.0, -1.0);
    glVertex3f(1.0, 1.0, -1.0);
    glVertex3f(1.0, 1.0, 1.0);
    glEnd();
    
    glBegin(GL_POLYGON);
    glVertex3f(-1.0, -1.0,-1.0);
    glVertex3f(-1.0, -1.0, 1.0);
    glVertex3f(-1.0, 1.0, 1.0);
    glVertex3f(-1.0, 1.0, -1.0);
    glEnd();
    glPopMatrix();
};

void Track::drawV2(){
    glPushMatrix();
    
    if(glIsEnabled(GL_LIGHTING))
        material(amb, diffuse, specular, &shine);
    glColor3f(0.55f, 0.35f, 0.05f);

    // the scale is the factor of reduction from the actual table size
    // 1 means no reduction where gm.TABLE_SIZE means full reduction
    float scale = 1.0f;
    // size of each triangle strip,. the slower this number the bigger must
    // be the height and the widht. also, more detailed is the definition
    float size = 0.05f / QUALITY;
    // height and width of the triangle strip
    int height = 20 * QUALITY, width = 20 * QUALITY;
    // quadrant multiplication factors. the for loop bellow creates the table
    // repeting the same content from the first quadrant to the rest of the
    // quadrants. this variable allows that
    float mult[4][2] = {
        {1.0f, 1.0f},
        {1.0f, -1.0f},
        {-1.0f, -1.0f},
        {-1.0f, 1.0f},
    };
    // for each quadrant
    for(int times = 0; times < 4; times++){
        // for the amount gltrangles strips (height)
        for(int h = 0; h < height; h++){
            // inital positions for each row of triangle strips
            GLfloat posx_ini = 0.0f;
            GLfloat posy_ini = 0.0f + size * h;
            glBegin(GL_QUAD_STRIP);
            // for the amount of gltriangle strips (widths)
            for(int w = 0; w < width; w++){
                // creates line for gl triangle strip
                for(int j = 0; j < 2; j++){
                    // defines x and y line and records vertex
                    GLfloat y = (posx_ini + size * w)/scale * mult[times][0],
                            x = (posy_ini + size * j)/scale * mult[times][1],
                            z = 0.0f;
                    glNormal3fv(normalize(x, y, z));
                    glVertex3f(x, y, z);
                }
            }
            glEnd();
        }
    }
    
//    // draw limits
//    // left
//    glPushMatrix();
//    glTranslatef(-1.0f, 0.0f, 2.0f);
//    glScalef(0.01f, 1.0f, 1.5f);
//    glutSolidCube(2);
//    glPopMatrix();
//    // right
//    glPushMatrix();
//    glTranslatef(1.0f, 0.0f, 2.0f);
//    glScalef(0.01f, 1.0f, 1.5f);
//    glutSolidCube(2);
//    glPopMatrix();
//    // top
//    glPushMatrix();
//    glTranslatef(0.0f, 1.0f, 2.0f);
//    glScalef(1.0f, 0.01f, 1.5f);
//    glutSolidCube(2);
//    glPopMatrix();
//    // bottom 
//    glPushMatrix();
//    glTranslatef(0.0f, -1.0f, 2.0f);
//    glScalef(1.0f, 0.01f, 1.5f);
//    glutSolidCube(2);
//    glPopMatrix();
//    
    glPopMatrix();
};

void Track::drawTrackModel(){
    switch (VERSION) {
        case 1: drawV1(); break;
        case 2: drawV2(); break;
        default: logger.error("Track version not available. Only V1 or V2");
            throw 0;
            break;
    }
};

void Track::draw(){
    logger.debug("Track::draw()");
	glPushMatrix();
    glTranslatef(_position->getX(), _position->getY(), _position->getZ());
    glScalef(gm.TRACK_SIZE, gm.TRACK_SIZE, 0.2f);
    // track is just a solid cube
    drawTrackModel();
    glPopMatrix();
};
