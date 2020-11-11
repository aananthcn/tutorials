#include <iostream>

using namespace std;

// Function Objects

template<typename T>
class Less_than {
        const T val; //value to compare against
        public:
        Less_than(const T& v) : val(v) {
                //constructor
        }

        bool operator()(const T& x) const {
                return x < val;
        }

}

struct X {
        int val;
        void out(const string &s, int nv) {
                cerr << this << "->" << s << ": " << val << " (" << nv << ")\n";
        }

        X() { // default constructor
                out("X()", 0);
                val = 0;
        }

        X(int v) {
                val = v;
                out("X(int)", v);
        }

        X(const X &x) { // copy constructor
                val = x.val;
                out("X(X&) ", x.val);
        }

        X &operator=(const X &a) { // copy asignment
                out("X::operator=()", a.val);
                val = a.val;
                return *this;
        }

        ~X() { out("~X()", 0); }
};

X glob(2); // a global variable

X copy(X a) { // object created while entry
         return a; // object created while return
}

X copy2(X a) { // objected created here
        X aa = a; // object created here
        return aa; // no object created here ??
}

X &ref_to(X &a) { return a; }

X *make(int i) {
        X a(i);
        return new X(a);
}

struct XX {
        X a;
        X b;
};

int main() { 
        cout << "\n *** Entering main() ***\n";

        X loc{4}; // local variable
        X loc2 {loc}; // copy construction

        cout << "\n// loc = X{5}; \n";
        loc = X{5}; // copy assignment
        cout << "\n// copy(loc); \n";
        loc2 = copy(loc); //call by value and return
        cout << "\n// copy2(loc); \n";
        loc2 = copy2(loc);
        cout << "\n// X loc3 {6}; \n";
        X loc3 {6};
        cout << "\n// X& r = ref_to(loc); \n";
        X& r = ref_to(loc);
        cout << "r.val = " << r.val << endl;
        cout << "\n// delete make(7); \n";
        delete make(7);
        cout << "\n// delete make(8); \n";
        delete make(8);

        cout << "\n// XX loc4; \n";
        XX loc4; // values not initialized

        cout << "\n// X* p = new X{9}; \n";
        X* p = new X{9};
        delete p;

        cout << "\n// X* pp = new X[5]; \n";
        X* pp = new X[5];
        delete[] pp;

        cout << "\n *** Exiting main() ***\n";
}