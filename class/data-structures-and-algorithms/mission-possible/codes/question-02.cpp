
#include <iostream>

using namespace std;

auto inputArray(unsigned length) {
	auto result = new int[length];
	for (auto i = result, e = i + length; i != e; ++i) {
		cin >> *i;
	}
	return result;
}

auto inputArrayReverse(unsigned length) {
	auto result = new int[length];
	auto i = result + length;
	do {
		--i;
		cin >> *i;
	} while (i != result);
	return result;
}

auto printArray(int *begin, int *end) {
	for ( ; begin != end; ++begin) {
		cout << *begin << '\x20';
	}
}

auto sort(int *begin, int *end, bool compare(int, int)) {
	auto swap = [](int &a, int &b) {
		auto t = a;
		a = b;
		b = t;
	};
	for ( ; begin != end; ++begin) {
		for (auto i = begin; i != end; ++i) {
			if (compare(*i, *begin)) {
				swap(*i, *begin);
			}
		}
	}
}

auto compareLess(int a, int b) {
	return a < b;
}

int main() {
	int *(*input)(unsigned);
	input_order:
	char order;
	cout << "Select input order:\n"
		"\tA: 0 --> n\n"
		"\tB: n --> 0\n";
	cin >> order;
	switch (order | '\x20') {
		case 'a':
			input = inputArray;
			break;
		case 'b':
			input = inputArrayReverse;
			break;
		default:
			cerr << "Invalid selection\n";
			goto input_order;
	}
	input_length:
	unsigned length;
	cout << "Enter array length: ";
	if (!(cin >> length)) {
		cerr << "Invalid input\n";
		goto input_length;
	}
	cout << "Enter all array elements: ";
	auto begin = input(length), end = begin + length;
	cout << "Array: ";
	printArray(begin, end);
	sort(begin, end, compareLess);
	cout << "\nIncrement array: ";
	printArray(begin, end);
	cout << endl;
	delete[] begin;
	return 0;
}
