#include <iostream>
#include <vector>
#include "reversed.cpp"

using namespace std;

int main() {
    vector<int> numbers = {1, 5, 3, 4, 2};
    for (auto i : numbers) {
        cout << i << ' ';
    }
    cout << "\n";
    vector<int> reversed = Reversed(numbers);
    for (auto i : reversed) {
        cout << i << ' ';
    }
    return 0;
}
