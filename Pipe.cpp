#include "Pipe.hpp"

Pipe::Pipe(int _x, int _y, int _height, Sprites *_sprites, Window *_win) : x(_x), y(_y), height(_height), sprites(_sprites), win(_win), x0(_x)
{
	ADD_HEAD_LEFT = "assets/sprites/objects/pipe/head-left.png";
	ADD_HEAD_RIGHT = "assets/sprites/objects/pipe/head-right.png";
	ADD_LEFT = "assets/sprites/objects/pipe/left.png";
	ADD_RIGHT = "assets/sprites/objects/pipe/right.png";
}

void Pipe::draw()
{
	Rectangle recDstHeadLeft(x, y, sprites->getSize(), sprites->getSize());
	win->draw_img(ADD_HEAD_LEFT, recDstHeadLeft, NULL_RECT);
	Rectangle recDstHeadRight(x + sprites->getSize(), y, sprites->getSize(), sprites->getSize());
	win->draw_img(ADD_HEAD_RIGHT, recDstHeadRight, NULL_RECT);
	for(int i = 1; i < height; i++)
	{
		Rectangle recDstRight(x + sprites->getSize(), y + sprites->getSize() * i, sprites->getSize(), sprites->getSize());
		win->draw_img(ADD_RIGHT, recDstRight, NULL_RECT);
		Rectangle recDstLeft(x, y + sprites->getSize() * i, sprites->getSize(), sprites->getSize());
		win->draw_img(ADD_LEFT, recDstLeft, NULL_RECT);
	}
}

void Pipe::shift(int cameraMove)
{
	x -= cameraMove;
}

void Pipe::reset()
{
	x = x0;
}

int Pipe::getX()
{
	return x;
}

int Pipe::getY()
{
	return y;
}