#include <iostream>

using namespace std;

void fun1(int);
void fun2(int);
void fun3(int, int);

int main()
{
	int x, y;
	cout << "Please enter first positive integer: " << endl;
	cin >> x;
	cout << "Please enter second positive integer: " << endl;
	cin >> y;
	
	fun1(x);
	fun2(x);
	fun3(x, y);
	return 0;
}

void fun1 (int i) //Count from 0 to parameter
{
	int x = 0;
	for (x; x<=i; x++)
	cout << x;
	cout << endl;
}

void fun2 (int x) //Count down from parameter to 0
{
	int i=x;
	for (i = x; i>=0; --i)
		cout << i;
		cout << endl;
}

void fun3 (int x, int y) //Count from one parameter to another
{
	int i;
	if (x > y)
	{
		for (i=y; i<=x; ++i)
			cout << i;
	}
	else
	{
		for (i=x; i<=y; ++i)
			cout << i;
	}
	cout << endl;
}
