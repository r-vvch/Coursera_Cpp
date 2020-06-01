#include <vector>
using namespace std;

vector<int> Reversed(const vector<int>& v) {
    vector<int> result;
    result.reserve(v.size());
for (int i = v.size() - 1; i >= 0; i--) {
        result.push_back(v[i]);
    }
    return result;
}