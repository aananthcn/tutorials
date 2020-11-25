#include <iostream>

using namespace std;

class Person {
public:
  	  	// interfaces
  	  	const string get_name() { return name; }
  	  	const string get_addr() { return address; }
  	  	void set_name(string s) { name = s; }
  	  	void set_addr(string s) { address = s; }

private:
  	  	// member function
  	  	string name;
  	  	string address;
};


istream& read(istream& is, Person& p) {
  	  	string str;
  	  	
  	  	cout << "Enter name:\n";
  	  	getline(is, str);
  	  	p.set_name(str);

  	  	cout << "Enter address: \n";
  	  	getline(is, str);
  	  	p.set_addr(str);

  	  	return is;
}

void print(ostream& os, Person& p) {
  	  	os << p.get_name() << " | " << p.get_addr();
}

int main() {
  	  	Person pers;
  	  	string ctrl;

  	  	while(read(cin, pers)) {
  	  	  	  	print(cout, pers);
  	  	  	  	cout << "\n\nContinue reading [Y]: ";
  	  	  	  	cin >> ctrl;
  	  	  	  	if ((ctrl == "n") || (ctrl == "N")) {
  	  	  	  	  	  	break;
  	  	  	  	}
  	  	  	  	cout << endl;
  	  	}
}