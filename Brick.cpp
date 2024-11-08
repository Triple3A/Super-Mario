#include "Brick.hpp"

Brick::Brick(int _x, int _y, Sprites *_sprites, Window *_win) : x(_x), y(_y), sprites(_sprites), win(_win), x0(_x) 
{
	ADD = "assets/sprites/objects/bricks_blocks/brick.png";
}

void Brick::draw()
{
	Rectangle rec_dst(x, y, sprites->getSize(), sprites->getSize());
	win->draw_img(ADD, rec_dst, NULL_RECT);
}

void Brick::shift(int cameraMove)
{
	x -= cameraMove;
}

void Brick::reset()
{
	x = x0;
}

int Brick::getX()
{
	return x;
}

int Brick::getY()
{
	return y;
}