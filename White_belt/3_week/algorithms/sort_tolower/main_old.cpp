#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

string tolower_string(const string& st) {
    string tolower_st;
    for (auto letter : st) {
        tolower_st.push_back(tolower(letter));
    }
    return tolower_st;
}

bool tolower_cmp(const string& a, const string& b) {
    string tolower_a = tolower_string(a), tolower_b = tolower_string(b);
    return tolower_a < tolower_b;
}

int main() {
    int N;
    cin >> N;
    vector<string> v(N);
    for (string& x : v) {
        cin >> x;
    }
    sort(v.begin(), v.end(), tolower_cmp);
    for (const auto& k : v) {
        cout << k << " ";
    }
    cout << endl;
    return 0;
}
