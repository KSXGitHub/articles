
/*
	YÊU CẦU BÀI TOÁN (hơi khác đề):
	 - Nhập m phần tử của một mảng A
	 - Nhập số nguyên n, chèn n vào A, bên phải phần tử gần n nhất
	PHƯƠNG PHÁP:
	 - Tìm vị trí phần tử k trong có giá trị gần n nhất: Giá trị |k - n| là nhỏ nhất
	 - Chèn n vào sau k
	CHÚ Ý:
	 - Không rõ bên phải ở đây là đằng sau hay đằng trước, nhưng rõ ràng là đề bài mơ hồ quá mức quy định
	 - Giả thiết là n được chèn vào sau k (giả thiết không cần c.m)
*/

#include <iostream>

using namespace std;

typedef int mang[32];

int main();
void nhap_mang(mang, unsigned &);
void xuat_mang(mang, unsigned);
unsigned tim_vi_tri(int, mang, unsigned);
unsigned tri_tuyet_doi(int);
void chen_sau(int, unsigned, mang, unsigned);

int main() {
	mang a;
	unsigned al;
	int n;
	cout << "Nhap do dai va cac phan tu cua mang A: ";
	nhap_mang(a, al);
	cout << "Nhap n: ";
	cin >> n;
	int vi_tri = tim_vi_tri(n, a, al);
	cout << "Phan tu gan n nhat la: a[" << vi_tri << "] = " << a[vi_tri] << endl;
	chen_sau(n, vi_tri, a, al);
	cout << "Xuat mang: ";
	xuat_mang(a, al + 1);
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
}

unsigned tim_vi_tri(int n, mang a, unsigned l) {
	unsigned res = 0; // vị trí
	for (unsigned i = 0; i != l; ++i) {
		if (tri_tuyet_doi(a[i] - n) < tri_tuyet_doi(a[res] - n)) { // Có cách khác hiệu quả hơn, nhưng cách này dễ hiểu
			res = i;
		}
	}
	return res + 1; // chèn vào sau, không phải vào trước
}

unsigned tri_tuyet_doi(int n) {
	return n > 0 ? n : -n;
}

void chen_sau(int n, unsigned vi_tri, mang a, unsigned l) {
	/*
		NGUYÊN TẮC:
		 - Duyệt từ cuối mảng đến vị trí cần chèn:
		  + Gán phần từ đằng trước cho phần tử đằng sau
		 - Khi đến vị trí cần chèn:
		  + Làm việc cần phải làm
	*/
	for ( ; vi_tri != l; --l) { // .....(blahblahblah)..... nhưng cách này đễ hiểu
		a[l] = a[l - 1];
	}
	a[vi_tri] = n;
}
