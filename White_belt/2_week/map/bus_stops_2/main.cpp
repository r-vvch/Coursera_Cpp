#include <iostream>
#include <map>
#include <vector>
#include <string>

using namespace std;

int main() {
    map<vector<string>, int> buses;
    int Q, N;
    cin >> Q;
    for (int i = 0; i < Q; i++) {
        cin >> N;
        vector<string> rout;
        string stop;
        for (int j = 0; j < N; j++) {
            cin >> stop;
            rout.push_back(stop);
        }
        if (buses.count(rout) == 0) {
            int num = buses.size() + 1;
            buses[rout] = num;
            cout << "New bus " << num << endl;
        } else {
            cout << "Already exists for " << buses[rout] << endl;
        }
    }
    return 0;
}
