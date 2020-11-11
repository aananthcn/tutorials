#include <iostream>

constexpr double square(double x) {
    return x*x;
}

int main() {
    constexpr double d1 {2.3};
    int i1 {(int)7.2};
    auto c1 = 'u';
    auto c2 = "µ"; // for multi-character font (unicode), use string

    double s1 = square(d1);

    std::cout << "Value of d1 = " << d1 << "\n";
    std::cout << "Value of 11 = " << i1 << "\n";
    std::cout << "Value of c1 = " << c1 << "\n";
    std::cout << "Value of c2 = " << c2 << "\n";
    std::cout << "Value of s1 = " << s1 << "\n";

    int* p1 = 0;

    if (p1 == nullptr) {
        std::cout << "Hey you passed the nullptr test!\n";
    }

    //section 1.8 test
    char answer = 0;
    doitagain:
    std::cout << "Do you want to proceed?\n";
    std::cin >> answer;
    if (answer == 'n') {
        goto doitagain;
    }

    double d2[] = {2.2, 3.6, 4.8};
    int i = 0;
    for (auto x : d2) {
        std::cout << "d1[" << i << "] = " << x << "\n";
        i++;
    }
}
