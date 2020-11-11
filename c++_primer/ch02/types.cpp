#include <iostream>

int main()
{
    bool b;
    char c;
    wchar_t wc;
    char16_t c16;
    char32_t c32;
    short s;
    int i;
    long l;
    long long ll;
    float f;
    double d;
    long double ld;

    std::cout << "size of b = " << sizeof(b) << "\n";
    std::cout << "size of c = " << sizeof(c) << "\n";
    std::cout << "size of wc = " << sizeof(wc) << "\n";
    std::cout << "size of c16 = " << sizeof(c16) << "\n";
    std::cout << "size of c32 = " << sizeof(c32) << "\n";
    std::cout << "size of s = " << sizeof(s) << "\n";
    std::cout << "size of i = " << sizeof(i) << "\n";
    std::cout << "size of l = " << sizeof(l) << "\n";
    std::cout << "size of ll = " << sizeof(ll) << "\n";
    std::cout << "size of f = " << sizeof(f) << "\n";
    std::cout << "size of d = " << sizeof(d) << "\n";
    std::cout << "size of ld = " << sizeof(ld) << "\n";
    signed char sc;
    std::cout << "size of sc = " << sizeof(sc) << "\n";

    unsigned u1 (42), u2 = 10;
    std::cout << "u1 - u2 = " << u1 - u2 << "\n";
    std::cout << "u2 - u1 = " << u2 - u1 << "\n";
    std::cout << "(unsigned)(u2 - u1) = " << (unsigned)(u2 - u1) << "\n";

    int i2 {42};
    i = 10;
    std::cout << "i2 - i = " << i2 - i << "\n";
    std::cout << "i - i2 = " << i - i2 << "\n";
    std::cout << "i - u1 = " << i - u1 << std::endl;
    std::cout << "u1 - i = " << u1 - i << "\n";
    return 0;
}