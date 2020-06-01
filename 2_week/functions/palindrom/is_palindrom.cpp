#include <string>

bool IsPalindrom(std::string w) {
    for (int i = 0; i < w.size() / 2 + 1; ++i) {
        if (w[i] != w[w.size() - i - 1]) {
            return false;
        }
    }
    return true;
}

