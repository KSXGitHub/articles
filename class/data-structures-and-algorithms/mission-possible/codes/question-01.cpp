
#include <iostream>
#include <string>

using namespace std;

unsigned sumNatureNumbers(unsigned quantity) {
	return quantity ? quantity + sumNatureNumbers(quantity - 1) : 0;
}

unsigned sumOddNumbers(unsigned quantity) {
	return quantity ? (quantity << 1) + sumOddNumbers(quantity - 1) - 1 : 0;
}

string toBinStr(unsigned dec) {
	return dec ? toBinStr(dec >> 1) + string(dec & 1 ? "1" : "0") : string();
}

int main() {
	unsigned n;
	cout << "n = ";
	cin >> n;
	cout << "\u03A3n = " << sumNatureNumbers(n) << endl;
	cout << "\u03A3(2n - 1) = " << sumOddNumbers(n) << endl;
	cout << "n = 0b" << toBinStr(n) << endl;
	return 0;
}
