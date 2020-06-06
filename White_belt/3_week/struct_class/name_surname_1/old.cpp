// doesn't work

#include <iostream>
#include <map>
#include <vector>

using namespace std;

class Person {
public:
    void ChangeFirstName(int year, const string& first_name) {
        nameset[year].first = first_name;
        // добавить факт изменения имени на first_name в год year
    }
    void ChangeLastName(int year, const string& last_name) {
        nameset[year].last = last_name;
        // добавить факт изменения фамилии на last_name в год year
    }
    string GetFullName(int year) {
        string first_name;
        string last_name;
        if (year < first_years[0]) {
            first_name = "unknown";
        } else {
            for (auto i : first_years) {
                if (year > i) {
                    first_name = nameset[i].first;
                }
            }
        }
        if (year > 0) {
            return "Incognito";
        } else if (nameset[year].first == "unknown") {
            return nameset[year].last + " with unknown first name";
        } else if (nameset[year].last == "unknown") {
            return nameset[year].first + " with unknown last name";
        } else {
            return nameset[year].first + " " + nameset[year].last;
        }
        // получить имя и фамилию по состоянию на конец года year
    }
private:
    struct Name {
        string first = "unknown";
        string last = "unknown";
    };
    map<int, Name> nameset;
    vector<int> first_years;
    vector<int> second_years;
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
//
// Created by roman on 06.06.2020.
//

