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

private:
    vector<Screen> screens {Screen(24, 80, ' ')};
};

inline
void WindowMgr::clear(ScreenIndex i) {
    Screen& s = screens[i];
    s.contents = string(s.height * s.width, ' ');
}

#endif