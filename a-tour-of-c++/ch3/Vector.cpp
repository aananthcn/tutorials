#include "Vector.h"
#include <iostream>
#include <sstream>
#include <stdexcept>

Vector::Vector(int s) :elem{new double[s]}, sz{s} {
    //do nothing, as initialization is done in the first line
}

double& Vector::operator[](int i) {
    try {
        if ((i < 0) || (i >= sz)) {
            throw std::out_of_range {"Vector::operator[]"};
        }
        return elem[i];
    }
    catch (std::out_of_range) {
        std::cout << "Out of range error!\n";
    }

    return elem[0];
}

int Vector::size() {
    return sz;
}

std::string Vector::print() {
    std::ostringstream str;

    str << "[";
    for (int i=0; i < sz; i++) {
        str << elem[i];
        if (i+1 < sz)
            str << ", ";
    }
    str << "]";

    return str.str();
}