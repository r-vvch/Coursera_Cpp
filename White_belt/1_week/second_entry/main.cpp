#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main() {
    string a;
    cin >> a;
    int num = 0;
    for (int i = 0; i < a.size(); ++i) {
        if (a[i] == 'f') {
            num += 1;
        }
        if (num == 2) {
            cout << i << endl;
            break;
        }
    }
    if (num == 1) {
        cout << -1;
    }
    if (num == 0) {
        cout << -2;
    }
    return 0;
}