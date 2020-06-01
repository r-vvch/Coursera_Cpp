#include <iostream>
#include <string>
#include <vector>
#include "move_strings.h"

using namespace std;

int main() {
    vector<string> source = {"a", "b", "c"};
    vector<string> destination = {"z"};
    MoveStrings(source, destination);
// source должен оказаться пустым
// destination должен содержать строки "z", "a", "b", "c" именно в таком порядке
    for (const auto& k : destination) {
        cout << k << " ";
    }
    return 0;
}