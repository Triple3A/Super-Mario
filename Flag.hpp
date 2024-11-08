#ifndef FLAG_H
#define FLAG_H

#include "src/rsdl.hpp"
#include "Sprites.hpp"

class Sprites;

class Flag
{
public:
	Flag(int _x, int _y, int _height, Sprites *_sprites, Window *_win);
	void draw();
	int getX();
	int getY();
	void shift(int cameraMove);
	void reset();
private:
	int x, y, x0, height;
	Sprites *sprites;
	Window *win;
	std::string ADD_HEAD;
	std::string ADD_BODY;
};
#endif