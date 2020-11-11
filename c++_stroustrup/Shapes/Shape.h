#ifndef SHAPES_CLASS_H
#define SHAPES_CLASS_H

#include "Point.h"

class Shape {
      public:
        virtual Point center() const = 0;
        virtual void move(Point to) = 0;
        virtual void draw() const = 0; // draw on current canvas
        virtual void rotate(int angle) = 0;
        virtual ~Shape() {}            // destructor
};

#endif