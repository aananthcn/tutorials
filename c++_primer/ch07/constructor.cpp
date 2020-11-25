#include <iostream>


class ConstRef {
public:
    // ConstRef(int ii) : ci(ii), ri(i), i(ci) {}  <== error! check the error! (ri = 32702)
    ConstRef(int ii) : ci(i), ri(i), i(ii) {} 
    int& geti() {return ri;}

private:
    int i;
    const int ci;
    int &ri;
};


struct X {
    X (int i, int j) : base(i), rem(base % j) {}
    //int rem, base;
    int base, rem;
};


int main() {
    ConstRef obj(10);
    int a = 0;

    std::cout << "ri = " << obj.geti() << "\n";
    a = obj.geti();

    int x, y;
    std::cout << "Enter 2 integers separated by space: ";
    std::cin >> x >> y;
    X obj2(x, y);
    std::cout << "\nbase = " << obj2.base << ", rem = " << obj2.rem << "\n";
    return 0;
}