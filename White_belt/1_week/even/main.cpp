#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main() {
    int A, B;
    cin >> A >> B;
    if (A % 2 == 0) {
        for (int i = A; i <= B; i += 2) {
            cout << i << ' ';
        }
    } else {
        for (int i = A + 1; i <= B; i += 2) {
            cout << i << ' ';
        }
    }
    return 0;
}