#ifndef WINDOWMGR_H
#define WINDOWMGR_H

#include <vector>
#include <iostream>

#include "Screen.h"
class Screen;

using namespace std;

class WindowMgr {
public:
  	  	// location ID for each screen on the window
  	  	using ScreenIndex = vector<Screen>::size_type;

  	  	// reset the Screen at the given position to all blanks
  	  	void clear(ScreenIndex);

  	  	// add a Screen to the window and returns its index
  	  	ScreenIndex addScreen(const Screen&);

  	  	// aananth's functions
  	  	int screen_mem_size() { return sizeof(screens); }
  	  	Screen& display_screen(ScreenIndex, ostream&);
  	  	Screen& get_screen(ScreenIndex i) { return screens[i]; } // bad coding! intentionally not checking the max index!!

private:
  	  	vector<Screen> screens {Screen(24, 80, ' ')};
  	  	int chumma = 0;
};

inline
void WindowMgr::clear(ScreenIndex i) {
  	  	Screen& s = screens[i];
  	  	s.contents = string(s.height * s.width, ' ');
}

inline
Screen& WindowMgr::display_screen(ScreenIndex i, ostream& os) {
  	  	screens[i].display(os);
}

inline
WindowMgr::ScreenIndex WindowMgr::addScreen(const Screen& scr) {
  	  	screens.push_back(scr);
  	  	return screens.size() - 1;
}

#endif