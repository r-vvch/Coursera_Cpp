#include <iostream>

struct Incognizable {
    int x = 0;
    int y = 0;
};

int main() {
    Incognizable a;
    Incognizable b = {};
    Incognizable c = {5};
    std::cout << c.x << " " << c.y;
    Incognizable d = {0, 1};
    return 0;
}