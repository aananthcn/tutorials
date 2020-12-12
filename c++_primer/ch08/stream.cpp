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
        if (is.eof())
            cout << "input stream reach EOF\n";
        else if (is.bad())
            cout << "input stream reached bad state\n";
        else if (is.fail())
            cout << "input stream reached failed state\n";
        else
            cout << "input stream is in unknown error state!\n";
    }
    

    return 0;
}