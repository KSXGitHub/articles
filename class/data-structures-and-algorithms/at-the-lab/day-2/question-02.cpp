
#include <iostream>

using namespace std;

struct SinhVien {
	static const unsigned DODAI_MSSV = 8, DODAI_HOTEN = 32;
	typedef char MSSV[DODAI_MSSV], HoTen[DODAI_HOTEN];
	MSSV mssv;
	HoTen hoten;
	float d1, d2, d3;
};

struct DanhSachSinhVien {
	constexpr unsigned MAX_LENGTH = 255;
	SinhVien sinhvien[MAX_LENGTH];
	unsigned soluong;
};

int main();
void nhap(DanhSachSinhVien &);

int main() {
	DanhSachSinhVien danhsach;
	nhap(danhsach);
	return 0;
}

void nhap(DanhSachSinhVien &danhsach) {
	cout << "Nhap so luong sinh vien: ";
	cin >> danhsach.soluong;
	for (auto i = 0u; i != danhsach.soluong; ++i) {
		
	}
}
