#include <vector>
using namespace std;

void Reverse(vector<int>& v) {
    int swap = 0;
    for (int i = 0; i < v.size() / 2; i++) {
        swap = v[i];
        v[i] = v[v.size() - 1 - i];
        v[v.size() - 1 - i] = swap;
    }
}