
#include <iostream>

using namespace std;

int main();
double tong(unsigned, double);

int main() {
	unsigned n;
	double x;
	cout << "Nhap lan luot n va x: ";
	cin >> n >> x;
	cout << "S("<< n << ", " << x << ") = " << tong(n, x) << endl;
	return 0;
}

double tong(unsigned n, double x) {
	double S = 0, tich = 1;
	unsigned giaithua = 1;
	for (unsigned i = 0; i <= n; ++i) {
		tich *= x;
		giaithua *= i;
		S += tich / giaithua;
	}
	return S;
}
