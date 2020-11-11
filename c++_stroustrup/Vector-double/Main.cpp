#include <iostream>

#include "Vector.h"
#include "Container.h"
#include "ListContainer.h"
#include "VectorContainer.h"

using namespace std;


void use(Container& c)
{
        const int sz = c.size();

        for (int i = 0; i < sz; i++)
                cout << "Container "<< i << ": " << c[i] << endl;
}


int main(void) {
        Vector v(4);
        Vector v1 = {10, 20, 30, 40};
        int sum = 0;

        for (int i = 0; i < v.size(); i++) {
                cout << "Enter the value of vector no " << i << ": ";
                cin >> v[i];
                sum += v[i];
        }
        cout << "Sum of Vector v = " << sum << endl;

        sum = 0;
        for (int i = 0; i < v.size(); i++) {
                sum += v1[i];
        }
        cout << "Sum of Vector v1 = " << sum << endl;

        ListContainer lc = {1, 2, 3, 4, 5, 6, 7, 8, 9};
        VectorContainer vc{10, 20, 30, 40, 50, 60};

        use(lc);
        use(vc);

        Vector v2 = v1; // needs copy constructor here!!
        cout << "created V2\n";
        v2[0] = 10.5;

        cout << "Value of v1[0] = " << v1[0] << endl;
}