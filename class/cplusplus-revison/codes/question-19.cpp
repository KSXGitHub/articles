
/*
	YÊU CẦU BÀI TOÁN:
	 - Xuất mảng C là giao của A và B
	 - Mỗi phần tử trong C là duy nhất
*/

#include <iostream>

using namespace std;

#define DO_DAI 32

typedef int mang[DO_DAI];

int main();
void nhap_mang(mang, unsigned &);
void xuat_mang(mang, unsigned);
void giao(mang, unsigned, mang, unsigned, mang, unsigned &);
int tim(int, mang, unsigned);

int main() {
	mang a, b, c;
	unsigned al, bl, cl;
	cout << "NHAP MANG:\n";
	cout << "Nhap do dai va cac phan tu cua mang A: ";
	nhap_mang(a, al);
	cout << "Nhap do dai va cac phan tu cua mang B: ";
	nhap_mang(b, bl);
	cout << "XUAT MANG:\n";
	cout << "A: ";
	xuat_mang(a, al);
	cout << "B: ";
	xuat_mang(b, bl);
	giao(a, al, b, bl, c, cl);
	cout << "Cac phan tu co trong ca A va B: ";
	xuat_mang(c, cl);
	return 0;
}

void nhap_mang(mang a, unsigned &l) {
	cin >> l;
	for (unsigned i = 0; i != l; ++i) {
		cin >> a[i];
	}
}

void xuat_mang(mang a, unsigned l) {
	for (unsigned i = 0; i != l; ++i) {
		cout << '\x20' << a[i];
	}
	cout << endl;
}

void giao(mang a, unsigned al, mang b, unsigned bl, mang c, unsigned &cl) {
	cl = 0;
	for (unsigned i = 0; i != al; ++i) {
		if (tim(a[i], b, bl) && !tim(a[i], c, cl)) {
			c[cl] = a[i];
			++cl;
		}
	}
}

int tim(int e, mang a, unsigned l) {
	for (unsigned i = 0; i != l; ++i) {
		if (e == a[i]) {
			return 1;
		}
	}
	return 0;
}
