
#include <iostream> // Turbo C++: <iostream.h>

using namespace std; // Turbo C++: bỏ, không viết dòng này

#define DO_DAI 32

typedef char chuoi[DO_DAI];

int main();
void nhap(chuoi, chuoi);
unsigned dem(chuoi);
int kiem_tra(chuoi, chuoi);

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
