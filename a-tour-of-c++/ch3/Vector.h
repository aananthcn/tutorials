// Vector.h
#include <iostream>

class Vector {
private:
    double* elem;
    int sz;

public:
    Vector(int s);
    double& operator[](int i);
    int size();
    std::string print();
};