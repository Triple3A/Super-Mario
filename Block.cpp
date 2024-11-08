#include "Block.hpp"

Block::Block(int _x, int _y, Sprites *_sprites, Window *_win) : x(_x), y(_y), sprites(_sprites), win(_win), x0(_x)
{
	ADD = "assets/sprites/objects/bricks_blocks/block.png";
}

void Block::draw()
{
	Rectangle rec_dst(x, y, sprites->getSize(), sprites->getSize());
	win->draw_img(ADD, rec_dst, NULL_RECT);
}

void Block::shift(int cameraMove)
{
	x -= cameraMove;
}

void Block::reset()
{
	x = x0;
}

int Block::getX()
{
	return x;
}

int Block::getY()
{
	return y;
}