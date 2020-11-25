#include <iostream>
#include "Screen.h"


using namespace std;

/////////////////////////////////
// Ex 7.34
int height;
class Screen2 {
public:
  	  	typedef string::size_type pos;
  	  	void setHeight(pos);
  	  	pos height = 0;
};

Screen2::pos verify(Screen2::pos); // class member declared outside
void Screen2::setHeight(Screen2::pos var) {
  	  	height = verify(var);
}

Screen2::pos verify(Screen2::pos v) { // definition of the class member defined outside
  	  	return v;
}

/////////////////////////////////
// Ex 7.35
typedef string Type;
Type initVal();

class Exercise {
public:
  	  	typedef double Type;
  	  	Type setVal(Type);
  	  	Type initVal() { val = 0; return (Type) val; }

private:
  	  	int val;
};

Exercise::Type Exercise::setVal(Type parm) {
  	  	val = parm + initVal();
  	  	return val;
}

int main() {
  	  	Screen scr(5, 6, 'a');

  	  	scr.display(cout);
  	  	scr.move(1, 2).set('B').set(2, 3, 'C').display(cout);
}
