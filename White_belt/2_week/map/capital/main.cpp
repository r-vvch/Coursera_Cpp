#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {
    map<string,string> capitals;

    int Q;
    cin >> Q;

    for (int i = 0; i < Q; ++i) {
        string command;
        cin >> command;
        if (command == "CHANGE_CAPITAL") {
            string country, new_capital;
            cin >> country >> new_capital;
            if (capitals.count(country) == 0) {
                cout << "Introduce new country " << country << " with capital " << new_capital << endl;
                capitals[country] = new_capital;
            } else if (capitals[country] == new_capital) {
                cout << "Country " << country << " hasn't changed its capital" << endl;
            } else {
                cout << "Country " << country << " has changed its capital from " << capitals[country] << " to " << new_capital << endl;
                capitals[country] = new_capital;
            }
        } else if (command == "RENAME") {
            string old_country_name, new_country_name;
            cin >> old_country_name >> new_country_name;
            if (old_country_name == new_country_name || capitals.count(old_country_name) == 0 || capitals.count(new_country_name) != 0) {
                cout << "Incorrect rename, skip" << endl;
            } else {
                cout << "Country " << old_country_name << " with capital " << capitals[old_country_name] << " has been renamed to " << new_country_name << endl;
                capitals[new_country_name] = capitals[old_country_name];
                capitals.erase(old_country_name);
            }
        } else if (command == "ABOUT") {
            string country;
            cin >> country;
            if (capitals.count(country) == 0) {
                cout << "Country " << country << " doesn't exist" << endl;
            } else {
                cout << "Country " << country << " has capital " << capitals[country] << endl;
            }
        } else if (command == "DUMP") {
            if (capitals.empty()) {
                cout << "There are no countries in the world" << endl;
            } else {
                for (const auto& item : capitals) {
                    cout << item.first << "/" << item.second << " ";
                }
                cout << endl;
            }
        }
    }
    return 0;
}