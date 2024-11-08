#include "Sprites.hpp"

Sprites::Sprites(int _elementHeight) :elementHeight(_elementHeight) {};

int Sprites::getSize()
{
	return elementHeight;
}

void Sprites::addBrick(Brick *brick)
{
	bricks.push_back(brick);
}

void Sprites::addBlock(Block *block)
{
	blocks.push_back(block);
}

void Sprites::addClay(Clay *clay)
{
	clays.push_back(clay);
}

void Sprites::addQuestion(Question *question)
{
	questions.push_back(question);
}

void Sprites::addFlag(Flag *flag)
{
	flags.push_back(flag);
}

void Sprites::addPipe(Pipe *_pipe)
{
	pipes.push_back(_pipe);
}


void Sprites::shift(int cameraMove)
{
	for(int i = 0; i < bricks.size(); i++)
	{
		bricks[i]->shift(cameraMove);
	}
	for(int i = 0; i < blocks.size(); i++)
	{
		blocks[i]->shift(cameraMove);
	}
	for(int i = 0; i < clays.size(); i++)
	{
		clays[i]->shift(cameraMove);
	}
	for(int i = 0; i < questions.size(); i++)
	{
		questions[i]->shift(cameraMove);
	}
	for(int i = 0; i < flags.size(); i++)
	{
		flags[i]->shift(cameraMove);
	}
	for(int i = 0; i < pipes.size(); i++)
	{
		pipes[i]->shift(cameraMove);
	}
}

void Sprites::reset()
{
	for(int i = 0; i < bricks.size(); i++)
	{
		bricks[i]->reset();
	}
	for(int i = 0; i < blocks.size(); i++)
	{
		blocks[i]->reset();
	}
	for(int i = 0; i < clays.size(); i++)
	{
		clays[i]->reset();
	}
	for(int i = 0; i < questions.size(); i++)
	{
		questions[i]->reset();
	}
	for(int i = 0; i < flags.size(); i++)
	{
		flags[i]->reset();
	}
	for(int i = 0; i < pipes.size(); i++)
	{
		pipes[i]->reset();
	}
}

void Sprites::draw(int numOfImg)
{
	for(int i = 0; i < bricks.size(); i++)
	{
		bricks[i]->draw();
	}
	for(int i = 0; i < blocks.size(); i++)
	{
		blocks[i]->draw();
	}
	for(int i = 0; i < clays.size(); i++)
	{
		clays[i]->draw();
	}
	for(int i = 0; i < questions.size(); i++)
	{
		questions[i]->draw(numOfImg);
	}
	for(int i = 0; i < flags.size(); i++)
	{
		flags[i]->draw();
	}
	for(int i = 0; i < pipes.size(); i++)
	{
		pipes[i]->draw();
	}
}

int Sprites::top(int _x, int _y)
{
	std::vector<int> y;
	for(int i = 0; i < bricks.size(); i++)
	{
		if(bricks[i]->getX() < _x + elementHeight && bricks[i]->getX() + elementHeight > _x)
			if(_y <= bricks[i]->getY())
				 y.push_back(bricks[i]->getY());
	}
	for(int i = 0; i < blocks.size(); i++)
	{
		if(blocks[i]->getX() < _x + elementHeight && blocks[i]->getX() + elementHeight > _x)
			if(_y <= blocks[i]->getY())
				y.push_back(blocks[i]->getY());
	}
	for(int i = 0; i < clays.size(); i++)
	{
		if(clays[i]->getX() < _x + elementHeight && clays[i]->getX() + elementHeight > _x)
			if(_y <= clays[i]->getY())
				y.push_back(clays[i]->getY());
	}
	for(int i = 0; i < questions.size(); i++)
	{
		if(questions[i]->getX() < _x + elementHeight && questions[i]->getX() + elementHeight > _x)
			if(_y <= questions[i]->getY())
				y.push_back(questions[i]->getY());
	}
	for(int i = 0; i < pipes.size(); i++)
	{
		if(pipes[i]->getX() < _x + elementHeight && pipes[i]->getX() + elementHeight * 2 > _x)
			if(_y <= pipes[i]->getY())
				y.push_back(pipes[i]->getY());
	}
	for(int i = 0; i < flags.size(); i++)
	{
		if(flags[i]->getX() < _x + elementHeight && flags[i]->getX() + elementHeight * 2 > _x)
			if(_y <= flags[i]->getY())
				y.push_back(flags[i]->getY());
	}
	if(y.size() == 0)
		return 1200;
	return min(y);
}

int Sprites::min(std::vector<int> numbers)
{
	int minn = numbers[0];
	for(int i = 1; i < numbers.size(); i++)
	{
		if(numbers[i] < minn)
			minn = numbers[i];
	}
	return minn;
}





