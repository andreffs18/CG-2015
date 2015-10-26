//
//  project_1_entrega - GameManager.h
//

#ifndef __GAMEMANAGER_H_INCLUDED__
#define __GAMEMANAGER_H_INCLUDED__

#include <vector>
#include "DynamicObject.h"
#include "StaticObject.h"
#include "Car.h"
#include "Track.h"
#include "Orange.h"
#include "Butter.h"
#include "Cheerio.h"

class GameManager {
private:
	std::vector<StaticObject *> _static_objects;
	std::vector<DynamicObject *> _dynamic_objects;
	int _current_time, _previous_time;

	Car * car;
	Track * track;
	Cheerio * cheerio;
	Butter * butter;
	Orange * orange;

	GLdouble * _init_quadrants(int);
public:
	// Global Variables
	// speed increment on car
	GLdouble SPEED_INCREMENT = 0.00025f;
	// max velocity allowed
	GLdouble MAX_VELOCITY = 0.01f;
	// steering direction angle increment
	GLdouble ANGLE_INCREMENT = 1.0f;
	// distance from the car in 3'rd person view
	GLdouble THIRDPERSON_DISTANCE = 5.0f;
	// car limits on track
	GLdouble TRACK_LIMITS = 18.5f;
	GLdouble TRACK_SIZE = 20.0f;
	// track inner circle
	float INNER_CIRCLE_RADIUS = 8.0;
	// track outer circle
	float OUTER_CIRCLE_RADIUS = 14.0;
	// qtd of object on table
	int QTD_CHEERIOS = 32;
	int QTD_ORANGES = 4;
	int QTD_BUTTERS = 4;
	// amount of scale that car increments or decrements when
	// on top of cheerios. Also limit of scaling on each cheerio
	float CAR_SCALE_DELTA = 0.005f;
	float CAR_MAX_SCALE_UP = 1.0f;
	float CAR_MAX_SCALE_DOWN = 0.2f;

	// array to decide if orange needs direction 
	bool SET_DIRECTION[4] = { true, true, true, true };
	// arrays to set which direction to go
	float XY_DIRECTION[4][2];
	// amount of increment of position
	double XY_INCREMENT[4][2];
	// amount of increase for speed of some time spent
	double INCREASE_FACTOR[4] = { 0.100, 0.100, 0.100, 0.100 };
	// to decide if speed must be increased
	bool INCREASE_SPEED[4] = { false, false, false, false };
	// counter to know which orange is being used
	int counter = 0;
	// initial time of each orange
	int TIME_ORANGES[4];
	float X_DIRECTION = 0.0f;
	float Y_DIRECTION = 0.0f;
	// variable that decides if moves in -x and/or -y
	float SET_NEG_X;
	float SET_NEG_Y;
	// initial velocidade of oranges
	float SPEED_INCREMENT_ORANGES = 0.25;
	float MAX_VELOCITY_ORANGES = 0.05;

	GameManager();
	~GameManager();

	void keyPress(int);
	void keyRelease(int);
	void drawAll();
	void updateAll();
	void handleColisions();
	void Cam1();
	void Cam2();
	void Cam3();

	static void onReshape(GLsizei w, GLsizei h);
	static void onDisplay();
	static void onKeyboard(unsigned char key, int x, int y);
	static void onSpecialKeys(int key, int x, int y);
	static void onSpecialKeysUp(int key, int x, int y);
	static void onMouseClick(int button, int state, int x, int y);
	static void onMouseMotion(int x, int y);
	static void onIdle();
};

#endif /* defined(__GAMEMANAGER_H_INCLUDED__) */