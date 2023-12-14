#include <iostream>

using namespace std;

int main() {
	int x = 1;
	int y = 1;
	int i;
	int n = 6;

	for (i = 2; i < n; i++) {
		y = x + y;
		x = y - x;
	}

	cout << "Number of Fibonachi: " << y;
}
