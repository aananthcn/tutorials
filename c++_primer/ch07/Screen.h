#ifndef SCREEN_H
#define SCREEN_H

#include <iostream>

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
