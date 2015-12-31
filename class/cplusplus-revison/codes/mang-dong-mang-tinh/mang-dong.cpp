
#include <iostream>

using namespace std;

int main();
int *nhapmang(unsigned);
void xuatmang(int *, unsigned);
int *congmang(int *, int *, unsigned);

int main() {
	unsigned n;
	cout << "Nhap do dai: ";
	cin >> n;
	cout << "Nhap mang A: ";
	int *A = nhapmang(n);
	cout << "Nhap mang B: ";
	int *B = nhapmang(n);
	int *C = congmang(A, B, n);
	cout << "A + B: ";
	xuatmang(C, n);
	delete[] A;
	delete[] B;
	delete[] C;
	return 0;
}

int *nhapmang(unsigned length) {
	int *result = new int[length];
	for (unsigned i = 0; i != length; ++i) {
		cin >> result[i];
	}
	return result;
}

void xuatmang(int *array, unsigned length) {
	for (unsigned i = 0; i != length; ++i) {
		cout << '\x20' << array[i];
	}
	cout << endl;
}

int *congmang(int *A, int *B, unsigned length) {
	int *result = new int[length];
	for (unsigned i = 0; i != length; ++i) {
		result[i] = A[i] + B[i];
	}
	return result;
}
