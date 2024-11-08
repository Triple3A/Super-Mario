#ifndef QUESTION_H
#define QUESTION_H

#include "src/rsdl.hpp"
#include "Sprites.hpp"

class Sprites;

class Question
{
public:
	Question(int _x, int _y, Sprites *_sprites, Window *_win);
	void draw(int numOfImg);
	int getX();
	int getY();
	void shift(int cameraMove);
	void reset();
private:
	int x, y, x0;
	Sprites *sprites;
	Window *win;
	std::vector<std::string> questions;
};
#endif