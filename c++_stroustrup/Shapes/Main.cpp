#include <iostream>

#include "Shape.h"
#include "Smiley.h"

using namespace std;


enum class Kind { circle, triangle, smiley };

void rotate_all(vector<Shape*>& v, int angle)
{
        for (auto p : v)
                p->rotate(angle);
}

Shape *read_shape(istream &is) {
        Kind k;
        Point p, p1, p2, p3;
        int r;
        Shape m, e1, e2;

        // read input from is
        switch (k) {
        case Kind::circle:
                // read radius and center point
                return new Circle{p, r};

        case Kind::triangle:
                // read p1, p2 p3
                return new Triangle{p1, p2, p3};

        case Kind::smiley:
                // read smiley data {point, int, shape, shape, shape} into
                // p, r, e1, e2 and m
                Smiley *ps = new Smiley{p, r};
                ps->add_eye(e1);
                ps->add_eye(e2);
                ps->set_mouth(m);
                return ps;
        }
}

void user() {
        std::vector<Shape*> v;
        while (cin)
                v.push_back(read_shape(cin));
        draw_all(v);
        rotate_all(v, 45);

        for (auto p : v)
                delete p;
}

int main(void)
{
        Point unipoint{1.0, 1.0};
        Smiley sm(unipoint, 5); // create a smiley @unipoint
        sm.move(Point(2.0, 2.0)); // move the smiley
        sm.rotate(30);
        sm.wink(2);
        sm.rotate(-30);

        user();

        cout << "Last line of main()\n";
}