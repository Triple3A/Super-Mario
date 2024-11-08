#ifndef CLAY_H
#define CLAY_H

#include "src/rsdl.hpp"
#include "Sprites.hpp"

class Sprites;

class Clay
{
public:
	Clay(int _x, int _y, Sprites *_sprites, Window *_win);
	void draw();
	int getX();
	int getY();
	void shift(int cameraMove);
	void reset();
private:
	int x, y, x0;
	Sprites *sprites;
	Window *win;
	std::string ADD;
};
#endif