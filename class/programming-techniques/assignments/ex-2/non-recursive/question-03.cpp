
#include <iostream>

using namespace std;

unsigned fibonacci(unsigned n ) {
    unsigned left = 0, right = 1;
    bool pos = false;
    for ( ; n; --n, pos = !pos) {
        if (pos) {
            right += left;
        } else {
            left += right;
        }
    }
    return pos ? right : left;
}

int main() {
    unsigned n;
    cout << "n = ";
    cin >> n;
    cout << "fibonacci(n) = " << fibonacci(n) << endl;
    return 0;
}
