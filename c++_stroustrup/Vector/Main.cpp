#include <iostream>
#include <list>
#include <string>

#include "Vector.h"

using namespace std;

template<typename T, int N>
struct Buffer {
        int size() const { return N; }
        T buf[N];
};

int main()
{
        Vector<char> vc(200);
        Vector<string> vs(17);
        Vector<list<int>> vli(45);

        Buffer<double, 1024> bufi; // buffer of 1K integer = 4K (in general)
        Buffer<char, 4096> bufc; // block size 4K

        cout << "size of bufi = " << sizeof(bufi) << endl;
        cout << "size of bufc = " << sizeof(bufc) << endl;
}