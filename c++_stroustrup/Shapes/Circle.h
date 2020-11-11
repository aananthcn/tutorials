#ifndef CIRCLE_SHAPE_H
#define CIRCLE_SHAPE_H

#include <iostream>

#include "Shape.h"
#include "Point.h"

class Circle : public Shape {
      public:
        Circle(Point p, int rr);

        Point center() const { return x; }

        void move(Point to) { x = to; }

        void draw() const;
        void rotate(int);

        ~Circle() { std::cout << "Circle's destructor called'\n"; }

      private:
        Point x;
        int r;
};

#endif