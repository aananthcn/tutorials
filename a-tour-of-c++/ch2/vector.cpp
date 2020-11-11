#include <iostream>


struct Vector_str {
    int sz;
    double* elem;
};

class Vector
{
private:
    double* elem;
    int sz;

public:
    //Vector(int s) : elem {new double[s]}, sz {s} {} // constructor
    Vector(int s) : elem (new double[s]), sz (s) {} // constructor
    int size() { return sz; }
    double& operator[](int i) { return elem[i]; }  //subscription
};

enum class TrafficLight { green, yellow, red };

TrafficLight& operator++(TrafficLight& t) {
    switch (t)
    {
    case TrafficLight::red:
        return t=TrafficLight::green;
    case TrafficLight::green:
        return t=TrafficLight::yellow;
    case TrafficLight::yellow:
        return t=TrafficLight::red;
    }
}

void vector_init(Vector_str& v, int s) {
    v.elem = new double[s];
    v.sz = s;
}

double read_and_sum(Vector_str& v) {
    int s = v.sz;

    for (int i = 0; i < s; i++) {
        std::cout << "Enter vector[" << i << "]\n";
        std::cin >> v.elem[i];
    }

    double sum = 0;
    for (int i = 0; i < s; i++) {
        sum += v.elem[i];
    }

    return sum;
}

double read_and_sum(Vector& v) {
    for (int i = 0; i < v.size(); i++) {
        std::cout << "Enter vector[" << i << "]\n";
        std::cin >> v[i];
    }

    double sum = 0;
    for (int i = 0; i < v.size(); i++) {
        sum += v[i];
    }

    return sum;
}

void f(Vector_str v, Vector_str& rv, Vector_str *pv) {
    std::cout << "Size of Vector v is: " << v.sz++ << "\n"; 
    std::cout << "Size of Vector v is: " << rv.sz++ << "\n"; 
    std::cout << "Size of Vector v is: " << pv->sz++ << "\n"; 
}

int main() {
    Vector_str vs;

    vector_init(vs, 5);
    int sum = read_and_sum(vs);
    std::cout << "Sum of all vector = " << sum << "\n";
    f(vs, vs, &vs);

    Vector v(6);
    sum = read_and_sum(v);
    std::cout << "Sum of all vector = " << sum << "\n";

    TrafficLight light = TrafficLight::red;
    light++;
    std::cout << "Traffic light after red is " << light << "\n";

    return 0;
}