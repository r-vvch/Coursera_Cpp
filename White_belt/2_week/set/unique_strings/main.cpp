#include <iostream>
#include <set>

using namespace std;

int main() {
    int N;
    cin >> N;
    set<string> unique_strings;
    for (int i = 0; i < N; ++i) {
        string a;
        cin >> a;
        unique_strings.insert(a);
    }
    cout << unique_strings.size();

    return 0;
}