#ifndef LIST_CONTAINER_CLASS_H
#define LIST_CONTAINER_CLASS_H

#include <list>
#include "Container.h"

class ListContainer : public Container {
        std::list<double> ld; // list of doubles

      public:
        ListContainer() {}
        ListContainer(std::initializer_list<double> il) : ld{il} {}
        ~ListContainer() {}

        double &operator[](int i);

        int size() const { return ld.size(); }
};

#endif