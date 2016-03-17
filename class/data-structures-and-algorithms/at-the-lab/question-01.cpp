
#include <iostream>

using namespace std;

const int MAX_LENGTH = 20;

struct Mang {
	int phantu[MAX_LENGTH];
	unsigned soluong;
};

int main();
void nhap(Mang &);
void xuat(Mang);
void sapxep(Mang &);
void swap(int &a, int &b);
void chen(Mang &, unsigned, int);

int main() {
	Mang mang;
	cout << "Nhap so luong va cac phan tu: ";
	nhap(mang);
	cout << "Mang da nhap: ";
	xuat(mang);
	sapxep(mang);
	cout << "Mang da sap xep: ";
	xuat(mang);
	unsigned vtchen;
	int ptchen;
	cout << "Nhap vi tri va phan tu can chen: ";
	cin >> vtchen >> ptchen;
	if (vtchen > mang.soluong) {
		cout << "Vi tri khong hop le\n";
	} else {
		chen(mang, vtchen, ptchen);
		cout << "Mang sau khi da chen phan tu " << ptchen << " vao vi tri " << vtchen << ": ";
		xuat(mang);
	}
	return 0;
}

void nhap(Mang &mang) {
	cin >> mang.soluong;
	for (unsigned i = 0; i != mang.soluong; ++i) {
		cin >> mang.phantu[i];
	}
}

void xuat(Mang mang) {
	for (unsigned i = 0; i != mang.soluong; ++i) {
		cout << mang.phantu[i] << '\x20';
	}
	cout << endl;
}

void sapxep(Mang &mang) {
	for (unsigned i = 0, e = mang.soluong - 1; i != e; ++i) {
		for (unsigned j = i + 1; j != mang.soluong; ++j) {
			if (mang.phantu[j] < mang.phantu[i]) {
				swap(mang.phantu[i], mang.phantu[j]);
			}
		}
	}
}

void swap(int &a, int &b) {
	int t = a;
	a = b;
	b = t;
}
