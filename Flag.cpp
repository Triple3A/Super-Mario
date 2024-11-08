#include "Flag.hpp"

Flag::Flag(int _x, int _y, int _height, Sprites *_sprites, Window *_win) : x(_x), y(_y), height(_height), sprites(_sprites), win(_win), x0(_x)
{
	ADD_HEAD = "assets/sprites/objects/flag/head.png";
	ADD_BODY = "assets/sprites/objects/flag/body.png";
}

void Flag::draw()
{
	Rectangle recDstHead(x, y, sprites->getSize(), sprites->getSize());
	win->draw_img(ADD_HEAD, recDstHead, NULL_RECT);
	for(int i = 1; i < height; i++)
	{
		Rectangle recDstBody(x, y + sprites->getSize() * i, sprites->getSize(), sprites->getSize());
		win->draw_img(ADD_BODY, recDstBody, NULL_RECT);
	}
}

void Flag::shift(int cameraMove)
{
	x -= cameraMove;
}

void Flag::reset()
{
	x = x0;
}

int Flag::getX()
{
	return x;
}

int Flag::getY()
{
	return y;
}