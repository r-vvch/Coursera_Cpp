#include <iostream>

using namespace std;

class Incognizable {
public:
    Incognizable() {}
    Incognizable(const int& mou) {
        first = mou;
    }
    Incognizable(const int& nani, const int& omaewa) {
        first = nani;
        second = omaewa;
    }
private:
    int first = 0;
    int second = 0;
};

int main() {
  Incognizable a;
  Incognizable b = {};
  Incognizable c = {0};
  Incognizable d = {0, 1};
  return 0;
}