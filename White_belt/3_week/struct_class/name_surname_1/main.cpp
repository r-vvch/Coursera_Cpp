#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

class Person {
public:
    void ChangeFirstName(int year, const string& first_name) {
        first_names[year] = first_name;
        first_name_years.push_back(year);
        sort(first_name_years.begin(), first_name_years.end());
        // добавить факт изменения имени на first_name в год year
    }
    void ChangeLastName(int year, const string& last_name) {
        last_names[year] = last_name;
        last_name_years.push_back(year);
        sort(last_name_years.begin(), last_name_years.end());
        // добавить факт изменения фамилии на last_name в год year
    }
    string GetFullName(int year) {
        string first_name;
        string last_name;
//        if (year < first_name_years[0]) {
//            first_name = "unknown";
//        }
//        if (year < last_name_years[0]) {
//            last_name = "unknown";
//        }
        for (const auto& i : first_names) {
            if (year >= i.first) {
                first_name = i.second;
            } else {
                break;
            }
        } // получили имя на момент этого года
        for (const auto& j : last_names) {
            if (year >= j.first) {
                last_name = j.second;
            } else {
                break;
            }
        } // получили фамилию на момент этого года
        if (first_name.empty() && last_name.empty()) {
            return "Incognito";
        } else if (first_name.empty()) {
            return last_name + " with unknown first name";
        } else if (last_name.empty()) {
            return first_name + " with unknown last name";
        } else {
            return first_name + " " + last_name;
        }
        // получить имя и фамилию по состоянию на конец года year
    }
private:
    map<int, string> first_names;
    map<int, string> last_names;
    vector<int> first_name_years;
    vector<int> last_name_years;
    // приватные поля
};

int main() {
    Person person;

    person.ChangeFirstName(1965, "Polina");
    person.ChangeLastName(1967, "Sergeeva");
    for (int year : {1900, 1965, 1990}) {
        cout << person.GetFullName(year) << endl;
    }

    person.ChangeFirstName(1970, "Appolinaria");
    for (int year : {1969, 1970}) {
        cout << person.GetFullName(year) << endl;
    }

    person.ChangeLastName(1968, "Volkova");
    for (int year : {1969, 1970}) {
        cout << person.GetFullName(year) << endl;
    }

    return 0;
}
