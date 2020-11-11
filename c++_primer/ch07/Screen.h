#ifndef SCREEN_H
#define SCREEN_H

#include <iostream>

using namespace std;

class Screen {
public:
    typedef string::size_type len;
    Screen() = default;
    Screen(len x, len y, char c): height(y), width(x), contents(x*y, c) {}
    void print();

    inline char get(len x, len y) const;
    Screen& set(len x, len y, char c);
    Screen& set(char c);
    Screen& move(len x, len y);

private:
    len cursor = 0;
    len height = 0, width = 0;
    string contents;
};

inline
void Screen::print() {
    cout << "---\n";
    for (auto i = 0; i < contents.length(); i++) {
        cout << contents[i];
        if ((i != 0) && ((i+1) % width == 0)) {
            cout << "\n";
        }
        else {
            cout << " ";
        }
    }
    cout << "\n";
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
