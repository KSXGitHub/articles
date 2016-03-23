
#include <iostream>
#include <cstring>

using namespace std;

constexpr auto BITLENGTH = sizeof(unsigned) * 8;
typedef char BinStr[BITLENGTH];

int main();
unsigned fromBinStr(BinStr);

int main() {
	BinStr bs;
	cout << "Nhap mot chuoi nhi phan: ";
	cin.getline(bs, BITLENGTH);
	cout << "Dang thap phan: " << fromBinStr(bs) << endl;
	return 0;
}

unsigned fromBinStr(BinStr bs) {
	if (*bs) {
		return ((*bs - '0') << 1) + fromBinStr(bs + 1);
	}
	return 0;
}
