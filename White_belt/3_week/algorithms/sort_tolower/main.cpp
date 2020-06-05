#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<string> v(N);
    for (string& x : v) {
        cin >> x;
    }
    sort(v.begin(), v.end(), [](string a, string b){
        return lexicographical_compare(a.begin(), a.end(), b.begin(), b.end(),
                [](char ch1, char ch2){ return tolower(ch1) < tolower(ch2);});
    });
    for (const auto& k : v) {
        cout << k << " ";
    }
    cout << endl;
    return 0;
}
