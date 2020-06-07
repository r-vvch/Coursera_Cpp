#include <iostream>
#include "main.cpp"

void f(int x) {
    cout << 'a';
    if (x % 2 == 0) {
        Weather weather("rain", 5);
        cout << 'b';
        return;
    }
    Weather weather2("fog", 4);
    cout << 'e';
}

int main() {
    f(6);
    return 0;
}