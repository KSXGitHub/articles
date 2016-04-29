
#include <iostream>

#define BEGIN_MATRIX(matrix) (&matrix[0][0])
#define END_MATRIX(matrix, size) (BEGIN_MATRIX(matrix) + size)

using namespace std;

constexpr unsigned ROWS = 4;
constexpr unsigned COLS = 5;
constexpr unsigned SIZE = ROWS * COLS;

typedef int Matrix[ROWS][COLS];
typedef int Array[SIZE];
typedef void sorter_t(int *, int *);

int main();
void input(Matrix);
void output(Matrix);
void input(int *, int *);
sorter_t *getsorter();
void bubble(int *, int *);
void shaker(int *, int *);
void swap(int *, int *);

int main() {
	Matrix matrix;
	cout << "Nhap mot ma tran 4x5:\n";
	input(matrix);
	sorter_t *sort = getsorter();
	cout << "Ma tran da nhap:\n";
	output(matrix);
	sort(BEGIN_MATRIX(matrix), END_MATRIX(matrix, SIZE));
	cout << "Ma tran da sap xep:\n";
	output(matrix);
	return 0;
}

void input(Matrix matrix) {
	input(BEGIN_MATRIX(matrix), END_MATRIX(matrix, SIZE));
}

void output(Matrix matrix) {
	for (unsigned i = 0; i != ROWS; ++i) {
		for (unsigned j = 0; j != COLS; ++j) {
			cout << '\x20' << matrix[i][j];
		}
		cout << endl;
	}
}

void input(int *begin, int *end) {
	for (int *i = begin; i != end; ++i) {
		cin >> *i;
	}
}

sorter_t *getsorter() {
	char x;
	begin:
	cout << "Kieu sap xep:\n - A: bubble-sort\n - B: shaker-sort\n";
	cin >> x;
	switch (x) {
		case 'A':
		case 'a':
			return &bubble;
		case 'B':
		case 'b':
			return &shaker;
	}
	cerr << "Sai lua chon: chi duoc nhap 'A' hoac 'B'\n";
	goto begin;
}

void bubble(int *begin, int *end) {
	for (int *i = begin, *e = end - 1; i != e; ++i) {
		bool done = true;
		for (int *j = e, *jj = j - 1; j != i; --j, --jj) {
			if (*j < *jj) {
				swap(j, jj);
				done = false;
			}
		}
		if (done) {
			return;
		}
	}
}

void shaker(int *begin, int *end) {
	int *left = begin;
	int *right = end - 1;
	unsigned k = unsigned(right);
	while (left < right) {
		for (int *i = right, *ii = i - 1; i != left; --i, --ii) {
			if (*i < *ii) {
				swap(i, ii);
				k = unsigned(i);
			}
		}
		left = (int *) k;
		for (int *i = left, *ii = i + 1; i != right; ++i, ++ii) {
			if (*i > *ii) {
				swap(i, ii);
				k = unsigned(i);
			}
		}
		right = (int *) k;
	}
}

void swap(int *a, int *b) {
	int t = *a;
	*a = *b;
	*b = t;
}
