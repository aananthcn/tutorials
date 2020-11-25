#include <iostream>
#include <vector>

#include "Screen.h"
#include "WindowMgr.h"

using namespace std;


int main() {
  	  	WindowMgr wmgr;
  	  	
  	  	cout << "Size of WindowMgr: " << sizeof(wmgr) << endl;
  	  	cout << "Size of screens: " << wmgr.screen_mem_size() << endl;

  	  	Screen& scr = wmgr.get_screen(0);
  	  	scr.set(1, 1, 'A').set(2,2, 'B');
  	  	wmgr.display_screen(0, cout);
  	  	wmgr.clear(0);
  	  	scr.set(12, 36, 'A').set(12, 37, 'a').set(12,38,'n').set(12,39,'a').set(12,40,'n').set(12,41,'t').set(12,42,'h');
  	  	wmgr.display_screen(0, cout);
}