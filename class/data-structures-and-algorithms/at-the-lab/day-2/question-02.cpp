
#include <iostream>

using namespace std;

int main();
unsigned sum(unsigned);

int main() {
	unsigned n;
	cout << "n = ";
	cin >> b;
	cout << "S(n) = " << sum(n) << endl;
	return 0;
}

unsigned sum(unsigned n) {
	return n && (n + sum(n - 1));
}
