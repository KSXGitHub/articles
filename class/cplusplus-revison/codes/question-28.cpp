
/*
	YÊU CẦU BÀI TOÁN:
	 - Nhập: Mảng A gồm n phần tử
	 - Xuất: Số lần xuất hiện của từng phần tử trong A, không xuất một giá trị quá một lần
	NGUYÊN TẮC:
	 - Dùng 3 mảng A, B, C:
	  + Mảng A chứa các giá trị người dùng nhập vào (input)
	  + Mảng B chứa các giá trị xuất hiện trong A, nhưng mỗi phần tử trong B là duy nhất (output)
	  + Mảng C chứa số lần xuất hiện của B trong A (output)
*/

#include <iostream>

using namespace std;

typedef int MangGiaTri[32];
typedef unsigned MangTanSo[32];

/* CÁC HÀM CẦN DÙNG */

// Chương trình chính
int main();

// Hàm nhập mảng
//  - A: Mảng cần nhập
//  - soluong: độ dài của mảng A
void nhapmang(MangGiaTri A, unsigned &soluong);

// Hàm xuất mảng
//  - B, C: Đã giải thích :)
//  - soluong: Độ dài của B, cũng là độ dài của C
void xuatmang(MangGiaTri B, MangTanSo C, unsigned soluong);

// Hàm liệt kê (Tạo B và C từ A)
//  - Chức năng:
//   + Đọc các giá trị từ A, kiểm tra trùng lặp, xem xét việc ghi vào B hoặc tăng tần số ở C (Xem giải thuật bên dưới)
//  - Input:
//   + Mảng A và độ dài của mảng
//  - Output:
//   + Mảng B, mảng C và độ dài của chúng
void lietke(MangGiaTri A, unsigned soluongA, MangGiaTri B, MangTanSo C, unsigned &soluongBC);

// Hàm tìm kiếm
//  - Chức năng:
//   + Tìm kiếm phần tử x trong X
//  - Input:
//   + Mảng X và độ dài của mảng
//   + Giá trị x
//  - Output:
//   + timthay: true/false
//   + vitri: nếu timthay là true, vitri là vị trí của x trong X
//  - Lưu ý:
//   + Trong Turbo C++ không có (bool, false, true), dùng (int, 0, 1) để thay thế
void timkiem(int x, MangGiaTri X, unsigned soluong, bool &timthay, unsigned &vitri);

/* ĐỊNH NGHĨA HÀM */

// Q: Tại sao mình lại viết main trước khi viết các hàm con mà không làm ngược lại?
//  A: Cần có cái nhìn bao quát toàn bộ về hướng đi của bài toán thì mới có thể viết một chương trình tốt, nhanh chóng, chính xác

int main() {
	MangGiaTri A, B;
	MangTanSo C;
	unsigned soluongA, soluongBC;
	cout << "Nhap so luong va cac phan tu cua mang A: ";
	nhapmang(A, soluongA);
	lietke(A, soluongA, B, C, soluongBC);
	cout << "So lan xuat hien cua tung gia tri trong A:\n";
	xuatmang(B, C, soluongBC);
	return 0;
}

void nhapmang(MangGiaTri A, unsigned &soluong) {
	cin >> soluong;
	for (unsigned i = 0; i != soluong; ++i) {
		cin >> A[i];
	}
}

void xuatmang(MangGiaTri B, MangTanSo C, unsigned soluong) {
	for (unsigned i = 0; i != soluong; ++i) {
		cout << '\t' << B[i] << " x" << C[i] << endl;
	}
}

void lietke(MangGiaTri A, unsigned soluongA, MangGiaTri B, MangTanSo C, unsigned &soluongBC) {
	soluongBC = 0;
	for (unsigned i = 0; i != soluongA; ++i) {
		bool timthay;
		unsigned vitri;
		timkiem(A[i], B, soluongBC, timthay, vitri);
		if (timthay) {
			++C[vitri];
		} else {
			B[soluongBC] = A[i];
			C[soluongBC] = 1;
			++soluongBC;
		}
	}
}

void timkiem(int x, MangGiaTri X, unsigned soluong, bool &timthay, unsigned &vitri) {
	for (unsigned i = 0; i != soluong; ++i) {
		if (x == X[i]) {
			timthay = true;
			vitri = i;
			return;
		}
	}
	timthay = false;
}
