
#include <iostream>

using namespace std;

int main();
unsigned UCLN(unsigned, unsigned);

int main() {
	unsigned a, b, c;
	cout << "Nhap 3 so nguyen: ";
	cin >> a >> b >> c;
	cout << "UCLN(a, b, c) = " << UCLN(UCLN(a, b), c) << endl;
	return 0;
}

unsigned UCLN(unsigned a, unsigned b) {
	if (a == b) {
		return a;
	}
	return a > b ? UCLN(a - b, b) : UCLN(b - a, a);
}
