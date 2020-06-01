#include <vector>
#include <string>

void MoveStrings(std::vector<std::string>& src, std::vector<std::string>& dst) {
    for (const auto& i : src) {
        dst.push_back(i);
    }
    src.clear();
}