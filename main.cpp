#include "CommandHandler.hpp"

using namespace std;

const string TITLE = "SUPER MARIO";
const string MAP_ADD = "assets/maps/1/1.txt";
const string BACKGROUNG_ADD = "assets/background_image.png";

int main(int argc, char** argv)
{
	Window *win = new Window(WINDOW_WIDTH, WINDOW_HEIGHT, TITLE);
	CommandHandler command(win);
	vector<string> mapLines = command.readFile(MAP_ADD);	
	try
	{
		command.updateMap(mapLines, BACKGROUNG_ADD);
	}
	catch (EndGame end)
	{
		win->clear();
		win->show_text("You Lose", Point(200, 150), RED , "OpenSans.ttf", 200);
		win->update_screen();
		delete(win);
		delay(5000);
		return 0;
	}
}