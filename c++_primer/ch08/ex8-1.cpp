#include <iostream>

using namespace std;

istream& read_stream(istream& ist) {
    static istream &is{ist};
    string str = "";

    char c;
    do {
        // read inputs
        if (is.good()) {
            is.get(c);
        }
        else {
            c = EOF;
        }

        // clean-up and exit.
        if (c == EOF) {
            str.append("\0");
            break;
        }
        else {
            str.append(1, c);
        }
    } while (1);

    cout << "\n\n====================\nPrinting text...\n====================\n";
    cout << str << "\n";

    return is;
}


int main() {
    //read_stream(cin);

    char i;
    while(cin >> i) { cout << i; }

    return 0;
}