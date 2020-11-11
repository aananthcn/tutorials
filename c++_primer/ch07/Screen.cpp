#include <iostream>
#include "Screen.h"


using namespace std;



int main() {
    Screen scr(5, 6, 'a');

    scr.print();
    scr.move(1, 2).set('B').set(2, 3, 'C').print();
}
