#include <iostream>
#include <vector>

using namespace std;

int main() {
    int a = 0;
    cin >> a;

    vector<int> bin;
    while (a > 0) {
        auto i = bin.cbegin();
        bin.insert(i, a % 2);
        a /= 2;
    }

    for (int n : bin) {
        std::cout << n;
    }

    return 0;
}