#include <iostream>

using namespace std;

class Sales_data {
public:
  	  	// member operations
  	  	string isbn() const { return bookNo; }
  	  	Sales_data& combine(const Sales_data&);
  	  	bool end_of_read();

  	  	// constructor
  	  	Sales_data() : bookNo("00-000"), units_sold(0), revenue(0) { } // not a good code as it is not using in-line initializer
		Sales_data(istream &is) { read(is, *this); }

private:
  	  	double avg_price() const;
  	  	
  	  	// data members
  	  	string bookNo;
  	  	unsigned units_sold = 0;
  	  	double revenue = 0.0;

public:
  	  	// friend declarations for nonmember Sales_data operations added
  	  	friend Sales_data add(const Sales_data &, const Sales_data &);
  	  	friend ostream &print(ostream &, const Sales_data &);
  	  	friend istream &read(istream &, Sales_data &);
};
#if 0
// declarations for nonmember parts of the Sales_data interface
Sales_data add(const Sales_data &, const Sales_data &);
ostream &print(ostream &, const Sales_data &);
istream &read(istream &, Sales_data &);
#endif
// member interface functions defintions
double Sales_data::avg_price() const {
  	  	if (units_sold)
  	  	  	  	return revenue / units_sold;
  	  	else
  	  	  	  	return 0;
}

Sales_data& Sales_data::combine(const Sales_data& rhs) {
  	  	units_sold += rhs.units_sold;
  	  	revenue += rhs.revenue;
  	  	return *this;
}

// non-member interface functions defintions
istream& read(istream& in, Sales_data& data) {
  	  	double price = 0.0;

  	  	cout << "Enter ISBN of the book:\n";
  	  	in >> data.bookNo;

  	  	cout << "Enter no of units sold:\n";
  	  	in >> data.units_sold;

  	  	cout << "Enter price of the book:\n";
  	  	in >> price;
  	  	data.revenue = data.units_sold * price;

  	  	return in;
}

ostream& print(ostream& os, const Sales_data& data) {
  	  	os << data.isbn() << " " << data.units_sold << " "
  	  	<< data.revenue << " " << data.avg_price();

  	  	return os;
}

bool Sales_data::end_of_read() {
  	  	if ((bookNo == ".") || (units_sold == 0))
  	  	  	  	return true;
  	  	else
  	  	  	  	return false;
}

int main()
{
	Sales_data test(cin);
	Sales_data total;

	if (read(cin, total)) {
		Sales_data trans;
		while (read(cin, trans)) {
			if (total.isbn() == trans.isbn())
				total.combine(trans);
			else {
				print(cout, total) << endl;
				total = trans;
			}
			if (trans.end_of_read()) {
				cout << "End of reading....\n";
				break;
			}
		}
		print(cout, total) << endl;
	}
	else {
		cerr << "No data?!" << endl;
	}

	return 0;
}