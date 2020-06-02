#include <iostream>
#include <vector>

using namespace std;

vector<int> avg_t(const vector<int>& temp) {
    int sum = 0;
    for (auto i : temp) {
        sum += i;
    }
    vector<int> result;
    float avg = float(sum) / temp.size();
    for (int i = 0; i < temp.size(); ++i) {
        if (float(temp[i]) > avg) {
             result.push_back(i);
        }
    }
    return result;
}

int main() {
    int N = 0;
    cin >> N;
    vector<int> input(N);
    for (auto& i : input) {
        cin >> i;
    }
    cout << avg_t(input).size() << endl;
    for (auto i : avg_t(input)) {
        cout << i << " ";
    }

    return 0;
}