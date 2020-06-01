#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::swap;

int main() {
    int a = 0, b = 0;
    cin >> a >> b;

    if (a < b) {
        swap(a, b);
    }
//    cout << "a: "<< a << "  b: " << b << endl;
//  a - большее число

    int div = 1;

    while (b > 0) {
        a %= b;
        swap(a,b);
//        cout << "a: "<< a << "  b: " << b << endl;
    }
    cout << a;

    return 0;
}