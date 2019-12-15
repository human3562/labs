#include <iostream>
#include <math.h>

using namespace std;

double a, b, startX, endX, dx;

double f(double x) {
	if (x <= a) {
		return exp(x);
	}
	else if (x < b && x > a) {
		return exp(x) + cos(x);
	}
	else if (x >= b) {
		return tan(x);
	}
}

int main()
{
	cout << "a = ";
	cin >> a;

	cout << "b = ";
	cin >> b;

	cout << "startX = ";
	cin >> startX;
	
	cout << "endX = ";
	cin >> endX;

	cout << "dx = ";
	cin >> dx;

	double firstval = f(startX);
	cout << '('<<startX<<';'<<firstval<<')';
	double max = firstval;
	double min = firstval;

	for (double i = startX+dx; i <= endX+dx; i += dx) {
		double val = f(i);
		cout << ", (" << i << ';' << val << ')';
		if (val > max) max = val;
		if (val < min) min = val;
	}



	cout << endl;
	cout << "max: " << max << endl;
	cout << "min: " << min << endl;

	return 0;
}
