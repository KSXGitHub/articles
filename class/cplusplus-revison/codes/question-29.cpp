
#include <iostream>

using namespace std;

#define DO_DAI 32

typedef int mang[DO_DAI];
typedef int mang_tron[2 * DO_DAI];

int main();
void nhap(mang, unsigned &);
int kiem_tra(mang, unsigned);
void xuat(mang, unsigned);
void tron(mang, mang, mang_tron);

int main() {
	mang a, b;
	mang_tron c;
	unsigned al, bl;
	cout << "Nhap do dai va cac phan tu cua mang a tang dan: ";
	nhap(a, al);
	cout << "Nhap do dai va cac phan tu cua mang b tang dan: ";
	nhap(b, bl);
	cout << "Mang a da nhap la: ";
	xuat(a, al);
	cout << "Mang b da nhap la: ";
	xuat(b, bl);
}

void nhap(mang a, unsigned &l) {
	begin:
	cin >> l;
	for (unsigned i = 0; i != l; ++i) {
		cin >> a[i];
	}
	if (!kiem_tra(a, l)) {
		cout << "Mang da nhap khong hop le. Nhap lai: ";
		goto begin;
	}
}

int kiem_tra(mang a, unsigned l) {
	int moc = a[0];
	for (unsigned i = 1; i < l; ++i) {
		if (a[i] > moc) {
			moc = a[i];
		} else {
			return 0;
		}
	}
	return 1;
}

void xuat(mang a, unsigned l) {
	for (int *i = a, *e = i + l; i != e; ++i) {
		cout << '\x20' << *i;
	}
	cout << endl;
}
