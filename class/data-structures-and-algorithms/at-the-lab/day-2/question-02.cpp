
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
	if (n) {
		return n + sum(n - 1);
	}
	return 0;
}
