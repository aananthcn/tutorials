#include <iostream>
#include <fstream>

#include "Sales_data.h"


using namespace std;


int main(int argc, char* argv[]) {
    cout << __FILE__ << endl;

    ifstream input(argv[1]);
    ofstream output(argv[2]);

    output << "ISBN-number\tUnits\tTotal\tAvg.Price" << endl;

    Sales_data total;

    if (read(input, total)) {
        Sales_data trans;

        while(read(input, trans)) {
            if (total.isbn() == trans.isbn()) {
                total.combine(trans);
            }
            else {
                print(output, total);
                total = trans;
            }
        }
        print(output, total);
    }

    return 0;
}