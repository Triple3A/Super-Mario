#ifndef MARIO_H
#define MARIO_H

#include "src/rsdl.hpp"
#include "Sprites.hpp"
#include <vector>

const int V_X = 20;
const int V_Y = 60;
const int G = -10;

class EndGame 
{
public:
	EndGame(std::string s) {};
};

class Sprites;

class Mario
{
public:
	Mario(int _x, int _y, Window *_win, int _elementHeight, Sprites *_sprites);
	int getX();
	void setX(int _x);
	void setVy0();
	void setVx0();
	void setVx(int _vx);
	int getVy();
	int getY();
	void setX0();
	void setY0();
	void movex(int forwardBackward, int i);
	void movey(int forwardBackward);
	void drawWalkingRight(int i);
	void drawStanding();
	void drawWalkingLeft(int i);
	int elementHeight;
	bool isSmall, isBig, isWhite;
	void decreaseLives();
	bool isTop();
private:
	Sprites *sprites;
	Window *win;
	int lastMove;
	int lives;
	int x, y, x0, _y0;
	int vx, vy;
	std::string dead;
	std::vector<std::string> smallWalkRight;
	std::vector<std::string> smallWalkLeft;
	std::string smallJumpingLeft;
	std::string smallJumpingRight;
	std::string smallSlidingRight;
	std::string smallSlidingLeft;
	std::string smallStandingRight;
	std::string smallStandingLeft;
	std::vector<std::string> bigWalkRight;
	std::vector<std::string> bigWalkLeft;
	std::string bigJumpingLeft;
	std::string bigJumpingRight;
	std::string bigSlidingRight;
	std::string bigSlidingLeft;
	std::string bigStandingRight;
	std::string bigStandingLeft;
	std::vector<std::string> whiteWalkRight;
	std::vector<std::string> whiteWalkLeft;
	std::string whiteJumpingLeft;
	std::string whiteJumpingRight;
	std::string whiteSlidingRight;
	std::string whiteSlidingLeft;
	std::string whiteStandingRight;
	std::string whiteStandingLeft;
	bool rightHit, leftHit, topHit, bottomHit;
};

#endif