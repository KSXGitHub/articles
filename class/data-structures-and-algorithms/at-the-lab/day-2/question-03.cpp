
#include <iostream>
#include <cstring>

using namespace std;

constexpr auto BITLENGTH = sizeof(unsigned) * 8;
typedef char BinStr[BITLENGTH];

int main();
unsigned fromBinStr(char *, unsigned);

int main() {
	BinStr bs;
	cout << "Nhap mot chuoi nhi phan: ";
	cin.getline(bs, BITLENGTH);
	unsigned length = strlen(bs);
	cout << "Dang thap phan: " << fromBinStr(bs + length - 1, length) << endl;
	return 0;
}

unsigned fromBinStr(char *end, unsigned length) {
	if (length) {
		return (*end - '0') + (fromBinStr(end - 1, length - 1) << 1);
	}
	return 0;
}
