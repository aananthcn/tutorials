#include "Vector.h"
#include <cmath>
#include <iostream>

using namespace std;

double sqrt_sum(Vector& v) {
    double sum = 0;
    for (int i=0; i < v.size(); ++i) {
        sum += sqrt(v[i]);
    }

    return sum;
}




int main() {
    Vector v(6);

    for (int i = 0; i < v.size(); i++) {
        cout << "Enter vector[" << i << "]\n";
        cin >> v[i];
    }

    cout << "Sum of square root of Vector: " << v.print() << " = " << sqrt_sum(v) << "\n";

    v[v.size()+1] = 0.98777702;
}