#include <iostream>
#include <map>
#include <string>

using namespace std;

map<char, int> BuildCharCounters(string& input) {
    map<char, int> m;
    for (auto i : input) {
        m[i]++;
    }
    return m;
}

string IsAnagrams(string& a, string& b) {
    if (BuildCharCounters(a) == BuildCharCounters(b)) {
        return "YES";
    } else {
        return "NO";
    }
}

int main() {
    int N;
    cin >> N;
    string first, second;
    for (int i = 0; i < N; i++) {
        cin >> first >> second;
        cout << IsAnagrams(first, second) << endl;
    }
    return 0;
}
