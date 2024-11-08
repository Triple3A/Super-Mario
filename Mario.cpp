#include "Mario.hpp"

Mario::Mario(int _x, int _y, Window *_win, int _elementHeight, Sprites *_sprites) : x(_x), y(_y), win(_win), elementHeight(_elementHeight), sprites(_sprites)
{
	lives = 3;
	x0 = _x;
	_y0 = _y;
	lastMove = 1;
	vy = 0;
	vx = 0;
	isSmall = true;
	isBig = false;
	isWhite = false;
	dead = "assets/sprites/mario/normal/dead.png";
	smallJumpingLeft = "assets/sprites/mario/normal/jumping-left.png";
	smallJumpingRight = "assets/sprites/mario/normal/jumping-right.png";
	smallSlidingRight = "assets/sprites/mario/normal/sliding-right.png";
	smallSlidingLeft = "assets/sprites/mario/normal/sliding-left.png";
	smallStandingRight = "assets/sprites/mario/normal/standing-right.png";
	smallStandingLeft = "assets/sprites/mario/normal/standing-left.png";
	
	bigJumpingLeft = "assets/sprites/mario/big/jumping-left.png";
	bigJumpingRight = "assets/sprites/mario/big/jumping-right.png";
	bigSlidingRight = "assets/sprites/mario/big/sliding-right.png";
	bigSlidingLeft = "assets/sprites/mario/big/sliding-left.png";
	bigStandingRight = "assets/sprites/mario/big/standing-right.png";
	bigStandingLeft = "assets/sprites/mario/big/standing-left.png";
	
	whiteJumpingLeft = "assets/sprites/mario/white/jumping-left.png";
	whiteJumpingRight = "assets/sprites/mario/white/jumping-right.png";
	whiteSlidingRight = "assets/sprites/mario/white/sliding-right.png";
	whiteSlidingLeft = "assets/sprites/mario/white/sliding-left.png";
	whiteStandingRight = "assets/sprites/mario/white/standing-right.png";
	whiteStandingLeft = "assets/sprites/mario/white/standing-left.png";	
	
	std::string s;
	
	s = "assets/sprites/mario/normal/walking-left-1.png";
	smallWalkLeft.push_back(s);
	s = "assets/sprites/mario/normal/walking-left-2.png";
	smallWalkLeft.push_back(s);
	s = "assets/sprites/mario/normal/walking-left-3.png";
	smallWalkLeft.push_back(s);
	s = "assets/sprites/mario/normal/walking-right-1.png";
	smallWalkRight.push_back(s);
	s = "assets/sprites/mario/normal/walking-right-2.png";
	smallWalkRight.push_back(s);
	s = "assets/sprites/mario/normal/walking-right-3.png";
	smallWalkRight.push_back(s);

	s = "assets/sprites/mario/big/walking-left-1.png";
	bigWalkLeft.push_back(s);
	s = "assets/sprites/mario/big/walking-left-2.png";
	bigWalkLeft.push_back(s);
	s = "assets/sprites/mario/big/walking-left-3.png";
	bigWalkLeft.push_back(s);
	s = "assets/sprites/mario/big/walking-right-1.png";
	bigWalkRight.push_back(s);
	s = "assets/sprites/mario/big/walking-right-2.png";
	bigWalkRight.push_back(s);
	s = "assets/sprites/mario/big/walking-right-3.png";
	bigWalkRight.push_back(s);
	
	s = "assets/sprites/mario/white/walking-left-1.png";
	whiteWalkLeft.push_back(s);
	s = "assets/sprites/mario/white/walking-left-2.png";
	whiteWalkLeft.push_back(s);
	s = "assets/sprites/mario/white/walking-left-3.png";
	whiteWalkLeft.push_back(s);
	s = "assets/sprites/mario/white/walking-right-1.png";
	whiteWalkRight.push_back(s);
	s = "assets/sprites/mario/white/walking-right-2.png";
	whiteWalkRight.push_back(s);
	s = "assets/sprites/mario/white/walking-right-3.png";
	whiteWalkRight.push_back(s);
}

void Mario::movex(int forwardBackward, int i)
{
	switch(forwardBackward)
	{
	case 1:
		drawWalkingRight(i);
		lastMove = 1;
		break;
	case -1:
		drawWalkingLeft(i);
		lastMove = -1;
		break;
	case 0:
		drawStanding();
		break;
	}
	// lastMove = forwardBackward;
}

void Mario::drawWalkingRight(int i)
{	
	Rectangle rec_dst(x, y, elementHeight, elementHeight);
	if(isSmall)
		win->draw_img(smallWalkRight[i], rec_dst, NULL_RECT);
	else if(isBig)
		win->draw_img(bigWalkRight[i], Rectangle(x, y, elementHeight, elementHeight * 2), NULL_RECT);
	else if(isWhite)
		win->draw_img(whiteWalkRight[i], Rectangle(x, y, elementHeight, elementHeight * 2), NULL_RECT);
}

void Mario::drawWalkingLeft(int i)
{
	Rectangle rec_dst(x, y, elementHeight, elementHeight);
	if(isSmall)
		win->draw_img(smallWalkLeft[i], rec_dst, NULL_RECT);
	else if(isBig)
		win->draw_img(bigWalkLeft[i], Rectangle(x, y, elementHeight, elementHeight * 2), NULL_RECT);
	else if(isWhite)
		win->draw_img(whiteWalkLeft[i], Rectangle(x, y, elementHeight, elementHeight * 2), NULL_RECT);
};

void Mario::drawStanding()
{
	if(lastMove == 1)
	{
		Rectangle rec_dst(x, y, elementHeight, elementHeight);
		if(isSmall)
			win->draw_img(smallStandingRight, rec_dst, NULL_RECT);
		else if(isBig)
			win->draw_img(bigStandingRight, Rectangle(x, y, elementHeight, elementHeight * 2), NULL_RECT);
		else if(isWhite)
			win->draw_img(whiteStandingRight, Rectangle(x, y, elementHeight, elementHeight * 2), NULL_RECT);
	}
	else if(lastMove == -1)
	{
		Rectangle rec_dst(x, y, elementHeight, elementHeight);
		if(isSmall)
			win->draw_img(smallStandingLeft, rec_dst, NULL_RECT);
		else if(isBig)
			win->draw_img(bigStandingLeft, Rectangle(x, y, elementHeight, elementHeight * 2), NULL_RECT);
		else if(isWhite)
			win->draw_img(whiteStandingLeft, Rectangle(x, y, elementHeight, elementHeight * 2), NULL_RECT);
	}
}

int Mario::getX()
{
	return x;
}

int Mario::getY()
{
	return y;
}

int Mario::getVy()
{
	return vy;
}

void Mario::setX(int _x)
{
	x = _x;
}

void Mario::setVy0()
{
	vy = V_Y;
}

void Mario::setVx0()
{
	vx = V_X;
}

void Mario::setVx(int _vx)
{
	vx = _vx;
}

void Mario::setX0()
{
	x = x0;
}

void Mario::setY0()
{
	y = _y0;
}

void Mario::movey(int forwardBackward)
{
	x += forwardBackward * vx;
	if(y + elementHeight <= sprites->top(x, y + elementHeight))
	{
		if(y + elementHeight - vy > sprites->top(x, y + elementHeight))
			y = sprites->top(x, y + elementHeight) - elementHeight;
		else
			y -= vy;
	}
	vy += G;
	if(y + elementHeight == sprites->top(x, y + elementHeight))
		vy = 0;
	if(y >= 1200 - 40)
		throw Exception("Restart");
}

void Mario::decreaseLives()
{
	lives--;
	win->draw_img(dead, Rectangle(x, y, elementHeight, elementHeight), NULL_RECT);
	if(lives == 0)
		throw EndGame("End");
}

bool Mario::isTop()
{
	if(y + elementHeight == sprites->top(x, y + elementHeight))
		return true;
	return false;
}
