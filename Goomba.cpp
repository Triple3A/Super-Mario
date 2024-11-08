#include "Goomba.hpp"

Goomba::Goomba(int _x, int _y, int _elementHeight, Window *_win, Sprites *_sprites, Enemies *_enemies) 
	:x(_x), y(_y), elementHeight(_elementHeight), win(_win), enemies(_enemies), x0(_x), _y0(_y), sprites(_sprites)
{
	dead = "assets/sprites/enemies/little_goomba/dead.png";
	std::string s;
	s = "assets/sprites/enemies/little_goomba/walking-1.png";
	walking.push_back(s);
	s = "assets/sprites/enemies/little_goomba/walking-2.png";
	walking.push_back(s);
}

void Goomba::draw(int numOfImg)
{
	Rectangle rec_dst(x, y, elementHeight, elementHeight);
	win->draw_img(walking[numOfImg], rec_dst, NULL_RECT);
}

void Goomba::shift(int cameraMove)
{
	x -= cameraMove;
}

void Goomba::reset()
{
	x = x0;
	y = _y0;
}

int Goomba::getX()
{
	return x;
}

int Goomba::getY()
{
	return y;
}