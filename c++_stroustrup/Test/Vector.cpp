#include <iostream>
#include <vector>

using namespace std;

int main()
{
	vector<int> v1{2, 4, 6};
	vector<int> v2;

	v2 = v1;

	cout << v2[2];

	return 0;
}
