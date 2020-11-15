#include <iostream>
#include <vector>

#include "Screen.h"
#include "WindowMgr.h"

using namespace std;


int main() {
    WindowMgr wmgr;
    
    cout << "Size of WindowMgr: " << sizeof(wmgr) << endl;
    cout << "Size of screens: " << sizeof(wmgr.screens) << endl;
}