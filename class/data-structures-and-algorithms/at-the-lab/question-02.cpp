
#include <iostream>

using namespace std;

struct SinhVien {
	static const unsigned DODAI_MSSV = 8, DODAI_HOTEN = 32;
	typedef char MSSV[DODAI_MSSV], HoTen[DODAI_HOTEN];
	MSSV mssv;
	HoTen hoten;
	float d1, d2, d3;
};
