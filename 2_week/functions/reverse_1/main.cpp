#include <iostream>
#include <vector>
#include "reverse.cpp"

using namespace std;

int main() {
    vector<int> numbers = {1, 5, 3, 4, 2};
    for (auto i : numbers) {
        cout << i << ' ';
    }
    cout << "\n";
    Reverse(numbers);
    for (auto i : numbers) {
        cout << i << ' ';
    }
    return 0;
}
