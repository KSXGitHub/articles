
#include <iostream>

using namespace std;

unsigned factorial(unsigned n) {
    unsigned result = 1;
    for ( ; n; --n) {
        result *= n;
    }
    return result;
}

int main() {
    unsigned n;
    cout << "n = ";
    cin >> n;
    cout << "n! = " << factorial(n) << endl;
    return 0;
}
