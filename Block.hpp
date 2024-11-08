#ifndef BLOCK_H
#define BLOCK_H

#include "src/rsdl.hpp"
#include "Sprites.hpp"

class Sprites;

class Block
{
public:
	Block(int _x, int _y, Sprites *_sprites, Window *_win);
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