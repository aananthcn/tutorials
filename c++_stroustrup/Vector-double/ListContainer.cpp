#include <stdexcept>
#include "ListContainer.h"

double &ListContainer::operator[](int i) {
        // not recommended as looping affects performance
        for (auto &x : ld) {
                if (i == 0)
                        return x;
                i--;
        }

        throw std::out_of_range("List container");
}