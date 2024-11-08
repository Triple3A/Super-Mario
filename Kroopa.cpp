#include "Kroopa.hpp"

Kroopa::Kroopa(int _x, int _y, int _elementHeight, Window *_win, Sprites *_sprites, Enemies *_enemies) 
	:x(_x), y(_y), elementHeight(_elementHeight), win(_win), enemies(_enemies), x0(_x), _y0(_y), sprites(_sprites)
{
	dead = "assets/sprites/enemies/koopa_troopa/dead.png";
	std::string s;
	s = "assets/sprites/enemies/koopa_troopa/walking-left-1.png";
	walkingLeft.push_back(s);
	s = "assets/sprites/enemies/koopa_troopa/walking-left-2.png";
	walkingLeft.push_back(s);
	s = "assets/sprites/enemies/koopa_troopa/walking-right-1.png";
	walkingRight.push_back(s);
	s = "assets/sprites/enemies/koopa_troopa/walking-right-2.png";
	walkingRight.push_back(s);
}

void Kroopa::draw(int numOfImg)
{
	Rectangle rec_dst(x, y, elementHeight, elementHeight);
	win->draw_img(walkingLeft[numOfImg], rec_dst, NULL_RECT);
}

void Kroopa::shift(int cameraMove)
{
	x -= cameraMove;
}

void Kroopa::reset()
{
	x = x0;
	y = _y0;
}

int Kroopa::getX()
{
	return x;
}

int Kroopa::getY()
{
	return y;
}