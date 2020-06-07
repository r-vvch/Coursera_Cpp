#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class ReversibleString {
public:
    ReversibleString() {}
    ReversibleString(const string& input) {
        S = input;
    }
    void Reverse() {
        reverse(begin(S), end(S));
    };
    string ToString() const {
        return S;
    }
private:
    string S;
};

int main() {
    ReversibleString s("live");
    s.Reverse();
    cout << s.ToString() << endl;

    s.Reverse();
    const ReversibleString& s_ref = s;
    string tmp = s_ref.ToString();
    cout << tmp << endl;

    ReversibleString empty;
    cout << '"' << empty.ToString() << '"' << endl;

    return 0;
}
