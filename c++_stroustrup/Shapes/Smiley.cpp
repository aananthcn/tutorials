#include <iostream>
#include "Smiley.h"

void Smiley::move(Point to) {
        std::cout << __FILE__ << "::" << __func__ << std::endl;
        Circle::move(to);
}

void Smiley::draw() const {
        Circle::draw();
        for (auto p : eyes)
                p->draw();
        mouth->draw();
}

void Smiley::wink(int i) {
        std::cout << __FILE__ << "::" << __func__ << std::endl;
}

void Smiley::rotate(int deg) {
        std::cout << __FILE__ << "::" << __func__ << std::endl;
        Circle::rotate(deg);
}