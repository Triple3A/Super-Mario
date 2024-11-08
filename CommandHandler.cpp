#include "CommandHandler.hpp"

CommandHandler::CommandHandler(Window *_win) :win(_win) {};

bool CommandHandler::process_event(const Event &event, int &screenStartPoint, int &numberOfImg, int &forward)
{
	switch(event.get_type())
	{
	case Event::QUIT:
		return false;
	case Event::KEY_PRESS:
		if (event.get_pressed_key() == 'd')
		{
			forward = 1;
			numberOfImg++;
			mario->setVx0();
			if(mario->getX() >= WINDOW_WIDTH / 2)
			{
				mario->setX(WINDOW_WIDTH / 2);
				screenStartPoint += CAMERA_MOVE;
				sprites->shift(CAMERA_MOVE * SCALE);
				enemies->shift(CAMERA_MOVE * SCALE);
				if(screenStartPoint >= BACKGROUND_WIDTH)
					screenStartPoint = 0;
			}
			return true;
		}
		if(event.get_pressed_key() == 'a')
		{
			forward = -1;
			numberOfImg++;
			mario->setVx0();
			if(mario->getX() <= 0)
				mario->setX(30);
		}
		if(event.get_pressed_key() == 'w')
		{
			if(mario->getX() >= WINDOW_WIDTH / 2)
			{
				mario->setX(WINDOW_WIDTH / 2);
				screenStartPoint += CAMERA_MOVE;
				sprites->shift(CAMERA_MOVE * SCALE);
				enemies->shift(CAMERA_MOVE * SCALE);
				if(screenStartPoint >= BACKGROUND_WIDTH)
					screenStartPoint = 0;
			}
			numberOfImg = 0;
			if(mario->getVy() == 0 && mario->isTop()) 
				mario->setVy0();
			return true;
		}
		break;
	case Event::KEY_RELEASE:
		if (event.get_pressed_key() == 'd' || event.get_pressed_key() == 'a')
			forward = 0;
		numberOfImg = 0;
		return true;
	default:
		if(mario->getX() > WINDOW_WIDTH / 2)
		{
			mario->setX(WINDOW_WIDTH / 2);
			screenStartPoint += CAMERA_MOVE;
			sprites->shift(CAMERA_MOVE * SCALE);
			enemies->shift(CAMERA_MOVE * SCALE);
			if(screenStartPoint >= BACKGROUND_WIDTH)
				screenStartPoint = 0;
		}
		numberOfImg++;
		break;
	}
	return true;
}

void CommandHandler::updateMap(std::vector<std::string> mapLines, std::string backgroundImgAdd)
{
	int screenStartPoint = 0;
	int numberOfImg = 0, forward = 0;
	win->play_music(BACKGROUND_SOUND);
	processMap(mapLines);
	while(process_event(win->poll_for_event(), screenStartPoint, numberOfImg, forward))
	{
		updateBackground(backgroundImgAdd, screenStartPoint);
		try
		{
			enemies->startMoving(CAMERA_MOVE / 2 * SCALE);
			sprites->draw(numberOfImg % 3);
			enemies->draw(numberOfImg % 2);
			mario->movey(forward);
			mario->movex(forward, numberOfImg % 3);
		}
		catch (Exception ex)
		{
			screenStartPoint = 0;
			mario->setX0();
			mario->setY0();
			sprites->reset();
			enemies->reset();
			mario->decreaseLives();
		}
		delay(50);
		win->update_screen();
	}
}

void CommandHandler::updateBackground(std::string backgroundImgAdd, int screenStartPoint)
{
	Rectangle rec_dst1(0, 0, WINDOW_WIDTH - screenStartPoint * SCALE, WINDOW_HEIGHT);
	Rectangle rec_src1(screenStartPoint, 0, BACKGROUND_WIDTH - screenStartPoint, BACKGROUND_HEIGHT);
	win->draw_img(backgroundImgAdd, rec_dst1, rec_src1);
	Rectangle rec_dst2(WINDOW_WIDTH - screenStartPoint * SCALE, 0, screenStartPoint * SCALE, WINDOW_HEIGHT);
	Rectangle rec_src2(0, 0, screenStartPoint, BACKGROUND_HEIGHT);
	win->draw_img(backgroundImgAdd, rec_dst2, rec_src2);
}

void CommandHandler::processMap(std::vector<std::string> mapLines)
{
	int elementHeight = WINDOW_HEIGHT / mapLines.size();
	sprites = new Sprites(elementHeight);
	enemies = new Enemies(elementHeight);
	for(int i = 0; i < mapLines.size(); i++)
	{
		for(int j = 0; j < mapLines[i].size(); j++)
		{
			createClasses(mapLines, i, j, elementHeight);
		}
	}
}

void CommandHandler::createClasses(std::vector<std::string> mapLines, int x, int y, int elementHeight)
{
	if(isBrick(mapLines[x][y]))
	{
		Brick *brick = new Brick(y * elementHeight, x * elementHeight, sprites, win);
		sprites->addBrick(brick);
	}
	else if(isBlock(mapLines[x][y]))
	{
		Block *block = new Block(y * elementHeight, x * elementHeight, sprites, win);
		sprites->addBlock(block);
	}
	else if(isClay(mapLines[x][y]))
	{
		Clay *clay = new Clay(y * elementHeight, x * elementHeight, sprites, win);
		sprites->addClay(clay);
	}
	if(isQuestion(mapLines[x][y]))
	{
		Question *question = new Question(y * elementHeight, x * elementHeight, sprites, win);
		sprites->addQuestion(question);
	}
	else if(isFlag(mapLines, x, y))
	{
		int height = getFlagHeight(mapLines, x, y);
		Flag *flag = new Flag(y * elementHeight, x * elementHeight, height, sprites, win);
		sprites->addFlag(flag);
	}
	else if(isPipe(mapLines, x, y))
	{
		int height = getPipeHeight(mapLines, x, y);
		Pipe *_pipe = new Pipe(y * elementHeight, x * elementHeight, height, sprites, win);
		sprites->addPipe(_pipe);
	}
	else if(mapLines[x][y] == MARIO)
	{
		mario = new Mario(y * elementHeight, x * elementHeight, win, elementHeight, sprites);
	}
	else if(mapLines[x][y] == GOOMBA)
	{
		Goomba *goomba = new Goomba(y * elementHeight, x * elementHeight, elementHeight, win, sprites, enemies);
		enemies->addGoomba(goomba);
	}
	else if(mapLines[x][y] == KROOPA)
	{
		Kroopa *kroopa = new Kroopa(y * elementHeight, x * elementHeight, elementHeight, win, sprites, enemies);
		enemies->addKroopa(kroopa);
	}
}

bool CommandHandler::isBrick(char element)
{
	if(element == BRICK)
		return true;
	return false;
}

bool CommandHandler::isBlock(char element)
{
	if(element == BLOCK)
		return true;
	return false;
}

bool CommandHandler::isClay(char element)
{
	if(element == CLAY)
		return true;
	return false;
}

bool CommandHandler::isQuestion(char element)
{
	if(element == QUESTION_C || element == QUESTION_M || element == QUESTION__H)
		return true;
	return false;
}

bool CommandHandler::isFlag(std::vector<std::string> mapLines, int x, int y)
{
	if(mapLines[x][y] == FLAG)
		if(mapLines[x - 1][y] != FLAG)
			return true;
	return false;
}

bool CommandHandler::isPipe(std::vector<std::string> mapLines, int x, int y)
{
	if(mapLines[x][y] == PIPE)
		if(mapLines[x][y - 1] != PIPE)
			if(mapLines[x - 1][y] != PIPE)
				return true;
	return false;
}

int CommandHandler::getFlagHeight(std::vector<std::string> mapLines, int x, int y)
{
	int height = 0;
	while(mapLines[x][y] == FLAG)
	{
		height++;
		x++;
	}
	return height;
}

int CommandHandler::getPipeHeight(std::vector<std::string> mapLines, int x, int y)
{
	int height = 0;
	while(mapLines[x][y] == PIPE)
	{
		height++;
		x++;
	}
	return height;
}



std::vector<std::string> CommandHandler::readFile(std::string fileName)
{
	std::ifstream file;
	file.open(fileName);
	std::string line;
	std::vector<std::string> lines;
	while (file >> line)
	{	
		lines.push_back(line);
	}
	file.close();
	return lines;
}

















