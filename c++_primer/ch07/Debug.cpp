#include <iostream>

#include "Debug.h"

using namespace std;

int main() {
    constexpr Debug io_sub(false, true, false); // IO debugging
    if (io_sub.any()) {
        cerr << "Error: io_sub - at least one flag set!!\n";
    }
    constexpr Debug prod(false);
    if (prod.any()) {
        cerr << "Error: prod - at least one flag set!!\n";
    }
    
    //io_sub.set_hw(true); Error - trying to change an object defined as constexpr
    //prod.set_others(true); Error - trying to change an object defined as constexpr

    Debug chumma(false);
    chumma.set_io(true);
    if (chumma.any()) {
        cerr << "Error: chumma - at least one flag set!!\n";
    }

    return 0;
}