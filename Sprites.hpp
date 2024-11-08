#ifndef SPRITES_H
#define SPRITES_H

#include <vector>
#include "Brick.hpp"
#include "Block.hpp"
#include "Clay.hpp"
#include "Flag.hpp"
#include "Pipe.hpp"
#include "Question.hpp"

class Brick;
class Block;
class Clay;
class Flag;
class Pipe;
class Question;

class Exception 
{
public:
	Exception(std::string s) {};
};

class Sprites
{
public:
	Sprites(int _elementHeight);
	int getSize();
	void addBrick(Brick *brick);
	void addBlock(Block *block);
	void addClay(Clay *clay);
	void addQuestion(Question *question);
	void addFlag(Flag *flag);
	void addPipe(Pipe *_pipe);
	void shift(int cameraMove);
	void reset();
	void draw(int numOfImg);
	int top(int _x, int _y);
	int min(std::vector<int> numbers);
private:
	int elementHeight;
	std::vector<Brick*> bricks;
	std::vector<Block*> blocks;
	std::vector<Clay*> clays;
	std::vector<Question*> questions;
	std::vector<Flag*> flags;
	std::vector<Pipe*> pipes;
};
#endif