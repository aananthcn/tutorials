#ifndef POINT_CLASS_H
#define POINT_CLASS_H

using namespace std;

class Point {
      public:
        Point() { x = y = 0; }
        Point(double a, double b) {
                x = a;
                y = b;
        }

        ~Point() { cout << "Point destructor called!!\n"; }

      private:
        double x;
        double y;
};

#endif