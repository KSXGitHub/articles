
#include <iostream>

using namespace std;

const int MAX_LENGTH = 20;

struct Mang {
	int phantu[MAX_LENGTH];
	unsigned dodai;
};

int main();
void khoitao(Mang &);
void nhap(Mang &);
void xuat(Mang &);

int main() {
	Mang mang;
	khoitao(mang);
	cout << "Nhap so luong va cac phan tu: ";
	nhap(mang);
	cout << "Mang da nhap: ";
	xuat(mang);
	return 0;
}
