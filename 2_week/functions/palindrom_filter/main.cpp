#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool IsPalindrom(std::string w);
vector<string> PalindromFilter(vector<string> words, int minLength);

int main() {
    vector<string> input = {"weew", "bro", "code"};
    for (auto i : PalindromFilter(input, 4)) {
        cout << i << " ";
    }
    return 0;
}