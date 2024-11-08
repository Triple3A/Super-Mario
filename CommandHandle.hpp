#ifndef COMMANDHANDLE_H
#define COMMANDHANDLE_H
#include "src/rsdl.hpp"
#include <fstream>
#include <vector>

class CommandHandle
{
public:
	bool process_event(const Event &event, int &i);
	void updateMap(string mapName, std::string mapFile, Window *win);
	std::vector<std::string> readfile(string fileName);
};