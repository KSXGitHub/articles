
#include <iostream>

using namespace std;

unsigned fibonacci(unsigned n) {
    switch (n) {
        case 0:
            return 0;
        case 1:
            return 1;
    }
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
    unsigned n;
    cout << "n = ";
    cin >> n;
    cout << "fibonacci(n) = " << fibonacci(n) << endl;
    return 0;
}
