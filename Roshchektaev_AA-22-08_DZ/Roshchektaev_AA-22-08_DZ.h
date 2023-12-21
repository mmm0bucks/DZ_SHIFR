#pragma once
#include <iostream>

using namespace std;

long int rekursia(int n)
{
	if (n == 1 || n == 2)
		return 1;
	if (n == 0)
		return 0;
	return rekursia(n - 1) + rekursia(n - 2);
}

long int dinamic_prog(int n) {
	int x = 1;
	int y = 1;
	int i;
	for (i = 2; i < n; i++) {
		y = x + y;
		x = y - x;
	}
	return y;
}

long int cycle(int n) {
	int a = 1, b = 1, c;
	if (n <= 2)
		return 1;
	else
	{
		for (int i = 3; i <= n; i++)
		{
			c = a + b;
			a = b; b = c;
		}
		return b;
	}
}

void zapusk() {
	int n;
	int d_y;
	int r_y;
	int c_y;
	cout << "n="; cin >> n;

	d_y = dinamic_prog(n);
	cout << "Number of Fibonachi (dynamic programming): " << d_y;

	cout << endl;

	r_y = rekursia(n);
	cout << "Number of Fibonachi (rekursia): " << r_y;

	cout << endl;

	c_y = cycle(n);
	cout << "Number of Fibonachi (cycle): " << c_y;
	cout << endl;
}