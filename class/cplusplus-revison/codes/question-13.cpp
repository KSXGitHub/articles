
#include <iostream>

using namespace std;

int main();
int kiem_tra(unsigned, unsigned &);

int main() {
	unsigned x, n;
	cout << "Nhap x: ";
	cin >> x;
	if (kiem_tra(x, n)) {
		cout << "x = n!\nn = " << n << endl;
	} else {
		cout << "Khong ton tai n sao cho x = n!\n";
	}
	return 0;
}

int kiem_tra(unsigned x, unsigned &n) {
	unsigned p = 1;
	n = 1;
	for ( ; ; ) {
		if (p == x) {
			return 1;
		}
		if (p > x) {
			return 0;
		}
		++n;
		p *= n;
	}
}
