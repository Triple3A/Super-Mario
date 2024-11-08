#ifndef COMMANDHANDLER_H
#define COMMANDHANDLER_H
#include "Sprites.hpp"
#include "Mario.hpp"
#include "Enemies.hpp"
#include <fstream>
#include <vector>

const int CAMERA_MOVE = V_X;
const int BACKGROUND_WIDTH = 2000;
const int BACKGROUND_HEIGHT = 1000;
const float SCALE = 1.0 * WINDOW_WIDTH / BACKGROUND_WIDTH;
const char BRICK = 'b';
const char BLOCK = '@';
const char CLAY = '#';
const char PIPE = '|';
const char FLAG = 'f';
const char MARIO = 'M';
const char GOOMBA = 'l';
const char KROOPA = 'k';
const char QUESTION_C = '?';
const char QUESTION_M = 'm';
const char QUESTION__H = 'h';
const std::string BACKGROUND_SOUND = "assets/sounds/Super Mario Bros. theme music.ogg";

class Enemies;
class Sprites;
class Brick;
class Block;
class Clay;
class Flag;
class Pipe;

class Mario;

class Exception;


class CommandHandler
{
public:
	CommandHandler(Window *_win);
	bool process_event(const Event &event, int &screenStartPoint, int &numberOfImg, int &forward);
	void updateMap(std::vector<std::string> mapLines, std::string backgroundImgAdd);
	void processMap(std::vector<std::string> mapLines);
	void updateBackground(std::string backgroundImgAdd, int screenStartPoint);
	void createClasses(std::vector<std::string> mapLines, int x, int y, int elementHeight);
	bool isBrick(char element);
	bool isBlock(char element);
	bool isClay(char element);
	bool isQuestion(char element);
	bool isFlag(std::vector<std::string> mapLines, int x, int y);
	bool isPipe(std::vector<std::string> mapLines, int x, int y);
	int getFlagHeight(std::vector<std::string> mapLines, int x, int y);
	int getPipeHeight(std::vector<std::string> mapLines, int x, int y);
	std::vector<std::string> readFile(std::string fileName);
private:
	Enemies *enemies;
	Sprites *sprites;
	Mario *mario;
	Window *win;
};
#endif