#include <iostream>

using namespace std;

int summation();

int main()
{
	summation();
	return 0;
}

int summation()
{
	int nvalue;
	int i;
	cout << "Here is a summation program! Please enter an n value: " << endl;
	cin >> nvalue;
	int sum = 0;
	for (i = 1; i < nvalue + 1; ++i)
	{
		sum = sum  + i^5 + 10;
	}

	cout << "Your final number is: " << sum << endl;
	return 0;
}
