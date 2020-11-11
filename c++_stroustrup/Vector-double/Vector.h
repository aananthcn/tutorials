#ifndef VECTOR_CLASS_H
#define VECTOR_CLASS_H

#include <iostream>

using namespace std;

class Vector {
      private:
        double *elem;
        int sz;

      public:
        Vector(int s) : elem{new double[s]}, sz{s} {
                for (int i = 0; i < s; i++) {
                        elem[i] = 0;
                }
                cout << "Memory for " << s << " elements allocated!!\n";
        }

        Vector(initializer_list<double>);
        Vector() {
                elem = nullptr;
                sz = 0;
        }
        
        // copy constructor
        Vector(const Vector& a) : elem{new double[a.sz]}, sz{a.sz} {
                for (int i=0; i != sz; ++i)
                        elem[i] = a.elem[i];
        }

        // move constructor
        Vector(Vector&& a) : elem{a.elem}, sz{a.sz} { // grabs a.elems
                a.elem = nullptr;
                a.sz = 0;
        }

        ~Vector() {
                if (elem) {
                        delete[] elem;
                        cout << "Vector memory deallocated!!\n";
                }
        }

        int size() const { return sz; }

        double &operator[](int i) { return elem[i]; }

        Vector read(istream &is) {
                Vector v;
                for (double d; is >> d;)
                        v.push_back(d);

                return v;
        }

        void push_back(double);

        Vector& operator=(const Vector& a); // copy assignment
        Vector& operator=(Vector&& a); // move assignment
};

#endif