// file for Coursera only; it does not participate in any way
set<string> BuildMapValuesSet(const map<int, string>& m) {
    set<string> map_values_set;
    for (const auto& item : m) {
        map_values_set.insert(item.second);
    }
    return map_values_set;
}
