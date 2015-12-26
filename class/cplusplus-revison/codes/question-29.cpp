
#include <iostream>

using namespace std;

#define DO_DAI 32

typedef int mang[DO_DAI];
typedef int mang_tron[2 * DO_DAI];

int main();
void nhap(mang, unsigned &);
void xuat(mang, unsigned);
void tron(mang, mang, mang_tron);

int main() {
	mang a, b;
	mang_tron c;
	unsigned al, bl;
	cout << "Nhap do dai va cac phan tu cua mang a: ";
	nhap(a, al);
	cout << "Nhap do dai va cac phan tu cua mang b: ";
	nhap(b, bl);
	cout << "Mang a da nhap la: ";
	xuat(a, al);
	cout << "Mang b da nhap la: ";
	xuat(b, bl);
}

void nhap(mang a, unsigned &l) {
	cin >> l;
	for (unsigned i = 0; i != l; ++i) {
		cin >> a[i];
	}
}

void xuat(mang a, unsigned l) {
	for (int *i = a, *e = i + l; i != e; ++i) {
		cout << '\x20' << *i;
	}
	cout << endl;
}
