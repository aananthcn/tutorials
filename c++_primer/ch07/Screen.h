#ifndef SCREEN_H
#define SCREEN_H

#include <iostream>

//#include "WindowMgr.h"
class WindowMgr;

using namespace std;

class Screen {
public:
    // member variables
    typedef string::size_type len;

    // constructors and destructors
    Screen() = default;
    Screen(len r, len c, char ch): height(r), width(c), contents(r*c, ch) {}

    // member functions
    inline char get(len r, len c) const;
    Screen& set(len r, len c, char ch);
    Screen& set(char ch);
    Screen& move(len r, len c);
    Screen& display(ostream& os) { do_display(os); return *this; }
    const Screen& display(ostream& os) const { do_display(os); return *this; }

private:
    // member variables
    len cursor = 0;
    len height = 0, width = 0;
    string contents;

    // friends
    friend class WindowMgr;

    // member functions
    void do_display(ostream& os) const;
};

inline
void Screen::do_display(ostream& os) const {
    os << "\n\nDisplay Contents:\n[ ";
    for (auto i = 0; i < contents.length(); i++) {
        if (contents[i] != ' ')
            os << contents[i];
        else {
            // print dots instead of space for better visualization
            os << '.'; 
        }
        if ((i != 0) && ((i+1) % width == 0)) {
            // check if this is last row
            if (i > (width * (height > 1 ? height-1 : -1)))
                os << " ]\n";
            else {
                // not a last line
                os << "\n  ";
            }
        }
    }
    os << "size: " << width << " x " << height << endl;
}

inline
Screen& Screen::move(len r, len c) {
    cursor = width * r + c; 
    return *this;
}

inline
Screen& Screen::set(len r, len c, char ch) {
    contents[width * r + c] = ch;
    return *this;
}

inline
Screen& Screen::set(char ch) {
    contents[cursor] = ch;
    return *this;
}

#endif
