
#include <iostream>

using namespace std;

const int MAX_LENGTH = 20;

struct Mang {
	int phantu[MAX_LENGTH];
	unsigned dodai;
};

int main();
void nhap(Mang &);
void xuat(Mang &);
void sapxep(Mang &);

int main() {
	Mang mang;
	cout << "Nhap so luong va cac phan tu: ";
	nhap(mang);
	cout << "Mang da nhap: ";
	xuat(mang);
	sapxep(mang);
	cout << "Mang da sap xep: ";
	xuat(mang);
	return 0;
}

void nhap(Mang &mang) {
	cin >> mang.dodai;
	for (unsigned i = 0; i != mang.dodai; ++i) {
		cin >> mang.phantu[i];
	}
}

void xuat(Mang &mang) {
	for (unsigned i = 0; i != mang.dodai; ++i) {
		cout << mang.phantu[i] << '\x20';
	}
	cout << endl;
}
