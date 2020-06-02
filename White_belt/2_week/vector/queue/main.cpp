#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void print_queue(const vector<bool>& a) {
    cout << "queue: ";
    for (auto i : a) {
        cout << i << " ";
    }
    cout << endl;
}

int main() {
    int N;
    string word;
    int number;
    cin >> N;
    vector<bool> queue;

    for (int i = 0; i < N; ++i) {
        cin >> word;
        if (word == "WORRY_COUNT") {
            cout << count(queue.begin(), queue.end(), true) << endl;
        } else {
            cin >> number;
            if (word == "COME") {
                queue.resize(queue.size() + number, false);
            } else if (word == "WORRY") {
                queue[number] = true;
            } else if (word == "QUIET") {
                queue[number] = false;
            }
        }
//        print_queue(queue);
    }

    return 0;
}
