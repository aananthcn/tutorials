#include <iostream>
#include <vector>

#include "Screen.h"

using namespace std;

class WindowMgr {
public:
    vector<Screen> screens { Screen(24, 80, ' '), Screen(40, 80, '0') };
};


int main() {
    WindowMgr wmgr;
    
    cout << "Size of WindowMgr: " << sizeof(wmgr) << endl;
    cout << "Size of screens: " << sizeof(wmgr.screens) << endl;
}