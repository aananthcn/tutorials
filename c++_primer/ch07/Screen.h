#ifndef SCREEN_H
#define SCREEN_H

#include <iostream>

// class declaration
class WindowMgr;

using namespace std;

class Screen {
public:
    // member variables
    typedef string::size_type pos;

    // constructors and destructors
    Screen() = default;
    Screen(pos r, pos c, char ch): height(r), width(c), contents(r*c, ch) {}

    // member functions
    inline char get(pos r, pos c) const;
    Screen& set(pos r, pos c, char ch);
    Screen& set(char ch);
    Screen& move(pos r, pos c);
    Screen& display(ostream& os) { do_display(os); return *this; }
    const Screen& display(ostream& os) const { do_display(os); return *this; }

private:
    // member variables
    pos cursor = 0;
    pos height = 0, width = 0;
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
Screen& Screen::move(pos r, pos c) {
    cursor = width * r + c; 
    return *this;
}

inline
Screen& Screen::set(pos r, pos c, char ch) {
    contents[width * r + c] = ch;
    return *this;
}

inline
Screen& Screen::set(char ch) {
    contents[cursor] = ch;
    return *this;
}

#endif
