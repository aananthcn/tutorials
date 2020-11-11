#include <iostream>

using namespace std;


void f() {
        cout << __func__ << ": ";
}

template<typename T>
void g(T x) {
        cout << __func__ << ": " << x << " ";
}

template<typename T, typename... Tail>
void f(T head, Tail... tail) {
        g(head);
        f(tail...);
} 

int main()
{
        cout << "first: ";
        f(1, 2.2, "hello");

        cout << "\nsecond: ";
        f(0.2, 'c', "yuck!", 0, 1, 2);
        cout << endl;
}