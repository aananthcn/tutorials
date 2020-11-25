#include <iostream>

using namespace std;

class Sales_data {
public:
  	  	// member operations
  	  	string isbn() const { return bookNo; }
  	  	Sales_data& combine(const Sales_data&);
  	  	void update_data(string bno, unsigned units, double price);
  	  	ostream& print(ostream&);
  	  	bool end_of_read();

  	  	// constructor
  	  	Sales_data() : bookNo("00-000"), units_sold(0), revenue(0) { } // not a good code as it is not using in-line initializer

private:
  	  	double avg_price() const;

  	  	// data members
  	  	string bookNo;
  	  	unsigned units_sold = 0;
  	  	double revenue = 0.0;
};

//nonmember Sales_data interface functions -- declarations
Sales_data add(const Sales_data&, const Sales_data&);
istream& read(istream &, Sales_data &);


// member interface functions defintions
void Sales_data::update_data(string bno, unsigned units, double price) {
  	  	bookNo = bno;
  	  	units_sold = units;
  	  	revenue = price * units;
}

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
  	  	string bno;
  	  	unsigned units;

  	  	cout << "Enter ISBN of the book:\n";
  	  	in >> bno;

  	  	cout << "Enter no of units sold:\n";
  	  	in >> units;

  	  	cout << "Enter price of the book:\n";
  	  	in >> price;
  	  	data.update_data(bno, units, price);

  	  	return in;
}

ostream& Sales_data::print(ostream& os) {
  	  	os << this->isbn() << " " << units_sold << " "
  	  	<< revenue << " " << this->avg_price();

  	  	return os;
}

bool Sales_data::end_of_read() {
  	  	if ((bookNo == ".") || (units_sold == 0)) {
  	  	  	  	cout << "End of reading....\n";
  	  	  	  	return true;
  	  	}

  	  	return false;
}

int main()
{
  	  	Sales_data total;
  	  	if (read(cin, total)) {
  	  	  	  	Sales_data trans;
  	  	  	  	while (read(cin, trans)) {
  	  	  	  	  	  	if (total.isbn() == trans.isbn())
  	  	  	  	  	  	  	  	total.combine(trans);
  	  	  	  	  	  	else {
  	  	  	  	  	  	  	  	total.print(cout) << endl;
  	  	  	  	  	  	  	  	total = trans;
  	  	  	  	  	  	}
  	  	  	  	  	  	if (trans.end_of_read()) {
  	  	  	  	  	  	  	  	break;
  	  	  	  	  	  	}
  	  	  	  	}
  	  	  	  	total.print(cout) << endl;
  	  	} else {
  	  	  	  	cerr << "No data?!" << endl;
  	  	}
  	  	return 0;
}