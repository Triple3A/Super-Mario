#include "Question.hpp"

Question::Question(int _x, int _y, Sprites *_sprites, Window *_win) : x(_x), y(_y), sprites(_sprites), win(_win), x0(_x) 
{
	std::string s;
	s = "assets/sprites/objects/bricks_blocks/question-1.png";
	questions.push_back(s);
	s = "assets/sprites/objects/bricks_blocks/question-2.png";
	questions.push_back(s);
	s = "assets/sprites/objects/bricks_blocks/question-3.png";
	questions.push_back(s);
}

void Question::draw(int numOfImg)
{
	Rectangle rec_dst(x, y, sprites->getSize(), sprites->getSize());
	win->draw_img(questions[numOfImg], rec_dst, NULL_RECT);
}

void Question::shift(int cameraMove)
{
	x -= cameraMove;
}

void Question::reset()
{
	x = x0;
}

int Question::getX()
{
	return x;
}

int Question::getY()
{
	return y;
}