#include "Clay.hpp"

Clay::Clay(int _x, int _y, Sprites *_sprites, Window *_win) : x(_x), y(_y), sprites(_sprites), win(_win), x0(_x)
{
	ADD = "assets/sprites/objects/bricks_blocks/clay.png";
}

void Clay::draw()
{
	Rectangle rec_dst(x, y, sprites->getSize(), sprites->getSize());
	win->draw_img(ADD, rec_dst, NULL_RECT);
}

void Clay::shift(int cameraMove)
{
	x -= cameraMove;
}

void Clay::reset()
{
	x = x0;
}

int Clay::getX()
{
	return x;
}

int Clay::getY()
{
	return y;
}