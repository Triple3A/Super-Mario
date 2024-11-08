#ifndef GOOMBA_H
#define GOOMBA_H

#include "src/rsdl.hpp"
#include "Enemies.hpp"
#include "Sprites.hpp"
#include <vector>

class Enemies;

class Goomba
{
public:
	Goomba(int _x, int _y, int _elementHeight, Window *_win, Sprites *_sprites, Enemies *_enemies);
	void draw(int numOfImg);
	void reset();
	void shift(int cameraMove);
	int getX();
	int getY();
private:
	int x, y, x0, _y0;
	int vx, vy;
	int elementHeight;
	Window *win;
	Sprites *sprites;
	Enemies *enemies;
	std::string dead;
	std::vector<std::string> walking;
};
#endif