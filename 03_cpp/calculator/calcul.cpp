#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	char o;
	double a, b;
	while (true)
	{
		cout << "enter your exercice" << endl;
		cin >> a >> o >> b;
		if  (o == '+')
		{ 
			cout << a + b << endl;
		}
		if  (o == '-')
        {
            cout << a - b << endl;
        }
		if  (o == '*')
        {
            cout << a * b << endl;
        }
		if  (o == '/')
        {
			if (b == 0) {
				cout << "Error" << endl;
			}
			else {
				cout << a / b << endl;
			}
        }
		if  (o == '^')
        {
			cout << pow(a, b) << endl;
        }
	}
	return 0;
}