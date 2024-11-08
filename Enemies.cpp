#include "Enemies.hpp"

Enemies::Enemies(int _elementHeight) :elementHeight(_elementHeight) {};

int Enemies::getSize()
{
	return elementHeight;
}

void Enemies::addGoomba(Goomba *goomba)
{
	goombas.push_back(goomba);
}

void Enemies::addKroopa(Kroopa *kroopa)
{
	kroopas.push_back(kroopa);
}

void Enemies::shift(int cameraMove)
{
	for(int i = 0; i < goombas.size(); i++)
	{
		goombas[i]->shift(cameraMove);
	}
	for(int i = 0; i < kroopas.size(); i++)
	{
		kroopas[i]->shift(cameraMove);
	}
}

void Enemies::reset()
{
	for(int i = 0; i < goombas.size(); i++)
	{
		goombas[i]->reset();
	}
	for(int i = 0; i < kroopas.size(); i++)
	{
		kroopas[i]->reset();
	}
}

void Enemies::draw(int numOfImg)
{
	for(int i = 0; i < goombas.size(); i++)
	{
		goombas[i]->draw(numOfImg);
	}
	for(int i = 0; i < kroopas.size(); i++)
	{
		kroopas[i]->draw(numOfImg);
	}
}

bool Enemies::isTop(int _x, int _y)
{
	for(int i = 0; i < goombas.size(); i++)
	{
		if(goombas[i]->getX() < _x + elementHeight && goombas[i]->getX() + elementHeight > _x)
			if(_y <= goombas[i]->getY())
				 return true;
	}
	for(int i = 0; i < kroopas.size(); i++)
	{
		if(kroopas[i]->getX() < _x + elementHeight && kroopas[i]->getX() + elementHeight > _x)
			if(_y <= kroopas[i]->getY())
				 return true;
	}
	return false;
}

int Enemies::top(int _x, int _y)
{
	for(int i = 0; i < goombas.size(); i++)
	{
		if(goombas[i]->getX() < _x + elementHeight && goombas[i]->getX() + elementHeight > _x)
			if(_y <= goombas[i]->getY())
				 return goombas[i]->getY();
	}
	for(int i = 0; i < kroopas.size(); i++)
	{
		if(kroopas[i]->getX() < _x + elementHeight && kroopas[i]->getX() + elementHeight > _x)
			if(_y <= kroopas[i]->getY())
				 return kroopas[i]->getY();
	}
}

void Enemies::startMoving(int cameraMove)
{
	for(int i = 0; i < goombas.size(); i++)
	{
		if(goombas[i]->getX() < WINDOW_WIDTH)
			goombas[i]->shift(cameraMove);
	}
	for(int i = 0; i < kroopas.size(); i++)
	{
		if(kroopas[i]->getX() < WINDOW_WIDTH)
			kroopas[i]->shift(cameraMove);
	}
}