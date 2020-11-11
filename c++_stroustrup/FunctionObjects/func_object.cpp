#include <iostream>
#include <vector>
#include <list>
#include <string>

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
                cout << "operator () is called!!\n";
                return x < val;
        }

};


template<typename C, typename P>
int count(const C& c, P pred) {
        int cnt = 0;
        for (const auto& x : c)
                if (pred(x))
                        ++cnt;
        return cnt;
}

void f(const vector<int>& vec, const list<string>& list, int x, const string& s) {
        cout << "number of values less than " << x << ": " << 
                count(vec, Less_than<int> {x}) << endl;
        cout << "number of values less than " << s << ": " << 
                count(list, Less_than<string> {s}) << endl;
}

void ff(const vector<int>& vec, const list<string>& list, int x, const string& s) {
        cout << "number of values less than " << x << ": " << 
                count(vec, [&](int a) {return a < x;}) << endl;
        cout << "number of values less than " << s << ": " << 
                count(list, [&](const string& a) {return a < s;}) << endl;
}


template<typename C, typename Oper>
void for_all(C& c, Oper op) {
        cout << "for_all output: ";
        for (auto& x : c) {
                cout << op(x) << " ";
        }
        cout << endl;
}

void user() {
        vector<int> v {1, 2, 3, 4, 5, 6, 7, 8, 9};

        for_all(v, [](int a) {return a*a;});
}


int main() {
        Less_than<int> lti {42};
        Less_than<string> lts {"Backup"};

        bool b1 = lti(42);
        bool b2 = lts("Aananth");

        cout << "Integer comparison result: " << b1 << endl;
        cout << "String comparison result: " << b2 << endl;

        vector<int> v {1,2,3,4,5};
        list<string> l {"Aananth", "Manoja", "Hardhik", "Saanika", "Natarajan", "Narayani"};

        f(v, l, 3, "Ibaco");
        ff(v, l, 4, "ibaco");

        user();

        return 0;
}