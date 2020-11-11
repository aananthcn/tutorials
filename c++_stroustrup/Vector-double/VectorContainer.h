#ifndef VECTOR_CONTAINER_CLASS_H
#define VECTOR_CONTAINER_CLASS_H

#include "Container.h"

class VectorContainer : public Container {
        Vector v;

      public:
        VectorContainer(int s) : v(s) {}
        VectorContainer(std::initializer_list<double> lst) : v{lst} {}
        ~VectorContainer() {}

        double &operator[](int i) { return v[i]; }

        int size() const { return v.size(); }
};

#endif