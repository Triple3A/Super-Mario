#ifndef ENEMIES_H
#define ENEMIES_H

#include <vector>
#include "Goomba.hpp"
#include "Kroopa.hpp"
#include "Sprites.hpp"

const int WINDOW_WIDTH = 1200;
const int WINDOW_HEIGHT = 600;

class Goomba;
class Kroopa;

class Exception; 

class Enemies
{
public:
	Enemies(int _elementHeight);
	int getSize();
	void startMoving(int cameraMove);
	void addGoomba(Goomba *goomba);
	void addKroopa(Kroopa *kroopa);
	void shift(int cameraMove);
	void reset();
	void draw(int numOfImg);
	int top(int _x, int _y);
	bool isTop(int _x, int _y);
private:
	int elementHeight;
	std::vector<Goomba*> goombas;
	std::vector<Kroopa*> kroopas;
};
#endif