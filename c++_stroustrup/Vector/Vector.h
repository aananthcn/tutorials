#ifndef VECTOR_CLASS_H
#define VECTOR_CLASS_H

#include <iostream>

using namespace std;

template<typename T>
class Vector {
private:
        T* elem;
        int sz;

public:
        explicit Vector(int s);
        ~Vector() { delete [] elem; }

        T& operator[](int i);
        const T& operator[](int i) const;
        int size() const { return sz;}
};

template<typename T>
Vector<T>::Vector(int s) {
        if (s < 0)
                throw invalid_argument{"Received negative values"};
        elem = new T[s];
        sz = s;

        cout << "Created " << s << " elements of size " << sizeof(T) << " bytes\n";
}


template<typename T>
const T& Vector<T>::operator[](int i) const {
        if (i < 0 || size() < 0)
                throw out_of_range{"Vector::operator[]"};
        return elem[i];
}

template<typename T>
T* begin(Vector<T>& x) {
        return x.size() ? &x[0] : nullptr;
}

template<typename T>
T* end(Vector<T>& x) {
        return begin(x)+x.size();
}


#endif