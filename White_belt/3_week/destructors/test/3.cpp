#include <iostream>
#include "main.cpp"

void f(int x) {
    cout << 'a';
    if (x % 2 == 1) {
        Weather weather("rain", 5);
        cout << 'b';
    }
    Weather weather2("fog", 4);
    cout << 'e';
}

int main() {
    f(11);
    return 0;
}