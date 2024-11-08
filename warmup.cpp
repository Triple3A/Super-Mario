#include "src/rsdl.hpp"
#include <vector>

#define x 290
#define y 290


using namespace std;

vector<Rectangle> crop(string fileName)
{
	vector<Rectangle> rec;
	
	Rectangle r0(x + 5,65 + y + 5, x, y);
	rec.push_back(r0);
	Rectangle r1(0, y + 5 + 60, x, y);
	rec.push_back(r1);
	Rectangle r2(x * 2 + 10, 65 + y * 2 + 10, x, y);
	rec.push_back(r2);
	Rectangle r3(x * 2 + 10, 65 + y + 5, x, y);
	rec.push_back(r3);
	Rectangle r4(0, 65 + 0, x,y);
	rec.push_back(r4);
	Rectangle r5(0, 65 + y * 2 + 10, x, y);
	rec.push_back(r5);
	Rectangle r6(x* 2 + 10,65 +  0, x, y);
	rec.push_back(r6);
	Rectangle r7(x + 5,65 +  y * 2 + 10,x, y);
	rec.push_back(r7);
	Rectangle r8(x + 5, 65 + 0,x, y);
	rec.push_back(r8);
	
	return rec;
}

void place(vector<Rectangle> rec, Window *win, vector<Rectangle> rec_dst)
{
	for(int i = 0; i < 9; i++)
	{
		win->draw_img("assets/warmup/warmup.png", rec_dst[i], rec[i]);
	}
}

bool process_event(const Event &event, Window *win, vector<Rectangle> rec, vector<Rectangle> rec_dst) {
  // static const string persons_names[] = {"Ghune", "Spartiate", "Athenian"};
  switch (event.get_type()) {
  case Event::QUIT:
    return false;
//   case Event::LCLICK:
//     persons.push_back(Person(persons_names[rand() % 3], rand() % 2,
//                              event.get_mouse_position()));
//     win->play_sound_effect("./example/assets/sound.wav");
//     break;
  case Event::KEY_PRESS:
    if (event.get_pressed_key() == 'r')
	{
		random_shuffle(rec.begin(), rec.end());
		for(int i = 0; i < 9; i++)
		{
			win->draw_img("assets/warmup/warmup.png", rec_dst[i], rec[i]);
		}
					win->update_screen();
		// place(rec, &win, rec_dst);
					break;
	}
  default:;
	  }
  return true;
}








int main()
{
    srand(time(NULL));
	vector<Rectangle> rec_dst;
	Rectangle r0(0, 0, x, y);
	rec_dst.push_back(r0);
	Rectangle r1(x + 5, 0, x,y);
	rec_dst.push_back(r1);
	Rectangle r2(x * 2 + 10, 0, x, y);
	rec_dst.push_back(r2);
	Rectangle r3(0, y + 5, x, y );
	rec_dst.push_back(r3);
	Rectangle r4(x+ 5, y + 5, x , y );
	rec_dst.push_back(r4);
	Rectangle r5(x * 2 + 10, y + 5, x , y );
	rec_dst.push_back(r5);
	Rectangle r6(0, y* 2 + 10, x, y);
	rec_dst.push_back(r6);
	Rectangle r7(x + 5, y* 2 + 10, x , y);
	rec_dst.push_back(r7);
	Rectangle r8(x * 2 + 10, y * 2 + 10, x, y );
	rec_dst.push_back(r8);
	Window win = Window(885, 885, "Warmup");
	vector<Rectangle> rec;
	rec = crop("assets/warmup/warmup.png");
	// while(1)
		while(process_event(win.poll_for_event(), &win, rec, rec_dst)) 
		{

			// random_shuffle(rec.begin(), rec.end());
// 			place(rec, &win, rec_dst);
		}
}