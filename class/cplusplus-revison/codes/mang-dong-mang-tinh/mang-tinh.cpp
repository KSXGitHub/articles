
#include <iostream>

using namespace std;

const unsigned nmax = 255;
typedef int mang[nmax];

int main();
void nhapmang(mang, unsigned);
void xuatmang(mang, unsigned);
void congmang(mang, mang, mang, unsigned);

int main() {
	mang A, B, C;
	unsigned n;
	cout << "Nhap do dai: ";
	cin >> n;
	cout << "Nhap mang A: ";
	nhapmang(A, n);
	cout << "Nhap mang B: ";
	nhapmang(B, n);
	congmang(A, B, C, n);
	cout << "A + B: ";
	xuatmang(C, n);
	return 0;
}

void nhapmang(mang X, unsigned n) {
	for (unsigned i = 0; i != n; ++i) {
		cin >> X[i];
	}
}

void xuatmang(mang X, unsigned n) {
	for (unsigned i = 0; i != n; ++i) {
		cout << '\x20' << X[i];
	}
	cout << endl;
}

void congmang(mang A, mang B, mang C, unsigned n) {
	for (unsigned i = 0; i != n; ++i) {
		C[i] = A[i] + B[i];
	}
}
