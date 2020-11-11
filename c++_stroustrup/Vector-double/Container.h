#ifndef CONTAINER_CLASS_H
#define CONTAINER_CLASS_H

class Container {
      public:
        virtual double& operator[](int) = 0;
        virtual int size() const = 0;
        virtual ~Container() {}
};

#endif