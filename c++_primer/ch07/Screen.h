#ifndef SCREEN_H
#define SCREEN_H

#include <iostream>

baba o basic_streambuf

#include "WindowMgr.h"

using namespace std;

class Screen {
public:
    // member variables
    typedef string::size_type len;

    // constructors and destructors
    Screen() = default;
    Screen(len x, len y, char c): height(y), width(x), contents(x*y, c) {}

    // member functions
    inline char get(len x, len y) const;
    Screen& set(len x, len y, char c);
    Screen& set(char c);
    Screen& move(len x, len y);
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
    os << "---\n";
    for (auto i = 0; i < contents.length(); i++) {
        os << contents[i];
        if ((i != 0) && ((i+1) % width == 0)) {
            os << "\n";
        }
        else {
            os << " ";
        }
    }
    os << "\n";
}

inline
Screen& Screen::move(len x, len y) {
    cursor = width * y + x; 
    return *this;
}

inline
Screen& Screen::set(len x, len y, char c) {
    contents[width * y + x] = c;
    return *this;
}

inline
Screen& Screen::set(char c) {
    contents[cursor] = c;
    return *this;
}

#endif
