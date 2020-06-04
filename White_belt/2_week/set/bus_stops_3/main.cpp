#include <iostream>
#include <set>
#include <map>

using namespace std;

void PrintSet(const set<string>& a) {
    for (const auto& i : a) {
        cout << i << " ";
    }
    cout << endl;
}

int main() {
    int Q;
    map<set<string>, int> routes;
    cin >> Q;
    int N = 0;
    for (int i = 0; i < Q; i++) {
        set<string> stops;
        cin >> N;
        string stop;
        for (int j = 0; j < N; j++) {
            cin >> stop;
            stops.insert(stop);
        }
        if (routes.count(stops) == 0) {
            routes[stops] = routes.size() + 1;
            cout << "New bus " << routes[stops] << endl;
        } else {
            cout << "Already exists for " << routes[stops] << endl;
        }
    }
    return 0;
}
