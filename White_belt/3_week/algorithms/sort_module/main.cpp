#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> v(N);
    for (int& x : v) {
        cin >> x;
    }
    sort(v.begin(), v.end(), [](int i, int j){ return (abs(i) < abs(j)); });
    for (const auto& k : v) {
        cout << k << " ";
    }
    cout << endl;
    return 0;
}
