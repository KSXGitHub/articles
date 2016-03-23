
#include <iostream>

using namespace std;

int main();
unsigned sum(unsigned);

int main() {
	unsigned n;
	cout << "n = ";
	cin >> n;
	cout << "S(n) = " << sum(n) << endl;
	return 0;
}

unsigned sum(unsigned n) {
	return n && (n + sum(n - 1));
}
