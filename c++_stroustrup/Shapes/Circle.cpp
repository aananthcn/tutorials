#include <iostream>

#include "Circle.h"


Circle::Circle(Point p, int rr) {
        x = p;
        r = rr;
}

void Circle::draw() const {
        std::cout << "Circle::draw() is called \n";
}

void Circle::rotate(int deg) {
        std::cout << __FILE__ << "::" << __func__ << std::endl;
}