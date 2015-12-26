
#include <iostream>

using namespace std;

#define DO_DAI 32;

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
}
