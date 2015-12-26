
#include <iostream> // Turbo C++: <iostream.h>
#include <string.h>

using namespace std; // Turbo C++: bỏ, không viết dòng này

#define DO_DAI 32

typedef char chuoi[DO_DAI];

int main();
void nhap(chuoi, chuoi);
unsigned dem(chuoi);
int kiem_tra(chuoi, chuoi);
int kiem_tra_tien_to(chuoi, char *);

int main() {
	chuoi s1, s2;
	nhap(s1, s2);
	unsigned s1l = dem(s1), s2l = dem(s2);
	cout << "Do dai chuoi s1: " << s1l << endl;
	cout << "Do dai chuoi s2: " << s2l << endl;
	int ket_qua_kiem_tra = s1l < s2l ? kiem_tra(s1, s2) : kiem_tra(s2, s1);
	if (ket_qua_kiem_tra) {
		cout << "Chuoi nho nam trong chuoi lon\n";
	} else {
		cout << "Chuoi nho khong nam trong chuoi lon\n";
	}
	return 0;
}

void nhap(chuoi s1, chuoi s2) {
	cout << "Nhap chuoi s1: ";
	cin.getline(s1, DO_DAI);
	cout << "Nhap chuoi s2: ";
	cin.getline(s2, DO_DAI);
}

unsigned dem(chuoi s) {
	unsigned ket_qua = 0;
	for (char *i = s; *i; ++i) { // Vòng lặp này dừng khi gặp '\0'
		++ket_qua;
	}
	return ket_qua;
}

int kiem_tra(chuoi nho, chuoi lon) {
	for (char *i = lon; *i; ++i) {
		if (kiem_tra_tien_to(nho, i)) {
			return 1; // Tìm thấy
		}
	}
	return 0; // Không tìm thấy
}

int kiem_tra_tien_to(chuoi nho, char *lon) {

	char *i, *ii;

	for (i = nho, ii = lon; *i == *ii; ++i, ++ii);

	// Nếu *i bằng null, trả về true
	return !(*i);

}
