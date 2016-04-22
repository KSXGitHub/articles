
#include <iostream>

using namespace std;

unsigned calc(unsigned n) {
    unsigned result = 0;
    for ( ; n; --n) {
        result += n * n;
    }
    return result;
}

int main() {
    unsigned n;
    cout << "n = ";
    cin >> n;
    cout << "Σ(n²) = " << calc(n) << endl;
    return 0;
}
