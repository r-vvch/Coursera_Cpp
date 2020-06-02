#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main() {
    double N, A, B, X, Y;
    cin >> N >> A >> B >> X >> Y;
    if (A > B) {
        if (N > A) {
            cout << N * (100 - X) * 0.01 << endl;
        } else if (N > B) {
            cout << N * (100 - Y) * 0.01 << endl;
        } else {
            cout << N << endl;
        }
    } else {
        if (N > B) {
            cout << N * (100 - Y) * 0.01 << endl;
        } else if (N > A) {
            cout << N * (100 - X) * 0.01 << endl;
        } else {
            cout << N << endl;
        }
    }

    return 0;
}