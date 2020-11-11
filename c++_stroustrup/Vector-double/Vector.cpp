#include <iostream>

#include "Vector.h"

using namespace std;

Vector::Vector(initializer_list<double> lst)
    : elem{new double[lst.size()]}, sz{static_cast<int>(lst.size())} {
        copy(lst.begin(), lst.end(), elem);
}

void Vector::push_back(double d) {
        // check the book
}

// copy assignment has strong association with copy constructor
Vector& Vector::operator=(const Vector& a) {
        double *p = new double [a.sz];
        for (int i=0; i != a.sz; ++i)
                p[i] = a.elem[i];
        delete[] elem; // delete old elements

        elem = p;
        sz = a.sz;

        return *this;
}