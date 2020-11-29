#include <iostream>
#include <vector>

#include "Account.h"

using namespace std;

double Account::interestRate = 0.7;


// Ex 7.58
class Example {
public:
    static double rate;
    static const int vecSize = 20;
    static vector<double> vec[vecSize];
};
// Ex 7.58
double Example::rate = 6.5;
//vector<double> Example::vec[];

int main() {
    Account ac1;
    Account *ac2 = &ac1;
    double r;
    r = Account::rate();

    cout << "r = " << r << "\n";
    Account::rate(0.9);
    r = ac1.rate();
    cout << "rate = " << ac2->rate() << ", r = " << r << "\n";
    cout << "sizeof(vector) = " << sizeof(vector<double>) << "\n";
    cout << "sizeof(vec) = " << sizeof(Example::vec) << "\n"; // expected: 20 * 24 = 480 bytes
}