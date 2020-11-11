#ifndef SMILEY_CLASS_H
#define SMILEY_CLASS_H

#include <vector>

#include "Circle.h"

using namespace std;

class Smiley : public Circle {
      public:
        Smiley(Point p, int r) : Circle{p, r}, mouth{nullptr} {}
        ~Smiley() {
                delete mouth;
                for (auto p : eyes)
                        delete p;

                cout << "Smiley destructor called!\n";
        }
        void move(Point to) override;
        void draw() const override;
        void rotate(int) override;
        void add_eye(Shape *s) { eyes.push_back(s); }
        void set_mouth(Shape *s);
        virtual void wink(int i); // wink the eye number

      private:
        vector<Shape *> eyes;
        Shape *mouth;
};

#endif