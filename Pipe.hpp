#ifndef PIPE_H
#define PIPE_H

#include "src/rsdl.hpp"
#include "Sprites.hpp"

class Sprites;

class Pipe
{
public:
	Pipe(int _x, int _y, int _height, Sprites *_sprites, Window *_win);
	void draw();
	int getX();
	int getY();
	void shift(int cameraMove);
	void reset();
private:
	int x, y, x0, height;
	Sprites *sprites;
	Window *win;
	std::string ADD_HEAD_LEFT;
	std::string ADD_HEAD_RIGHT;
	std::string ADD_LEFT;
	std::string ADD_RIGHT;
};
#endif