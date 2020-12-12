#include <iostream>


using namespace std;

int main() {
    istream &is{cin};
    int i;
    
    cout << "Enter a number: ";
    is >> i;

    if (is.good()) {
        cout << "input stream is in good shape!\n";
    }
    else {
        cout << "input stream is in error state!\n";
    }
    

    return 0;
}