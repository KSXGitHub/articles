
#include <iostream>

using namespace std;

unsigned calc(unsigned n) {
    return n ? n * n + calc(n - 1) : 0;
}

int main() {
    unsigned n;
    cout << "n = ";
    cin >> n;
    cout << "Σ(n²) = " << calc(n) << endl;
    return 0;
}
