#include <iostream>
#include <map>
#include <vector>

using namespace std;

class Person {
public:
    Person() {}
    Person(const string& first_name, const string& last_name, const int& year) {
        first_names[year] = first_name;
        last_names[year] = last_name;
        birth_year = year;
    }
    string PrintVectorUni(const vector<string>& v) const {
        if (v.empty()) {
            return "";
        }
        string prev;
        string output = " (";
        output += v[v.size() - 1];
        for (int i = v.size() - 2; i >= 0; i--) {
            output += ", " + v[i];
        }
        output += ")";
        return output;
    }
    void ChangeFirstName(int year, const string& first_name) {
        if (year >= birth_year) {
            first_names[year] = first_name;
        }
        // добавить факт изменения имени на first_name в год year
    }
    void ChangeLastName(int year, const string& last_name) {

        last_names[year] = last_name;
        // добавить факт изменения фамилии на last_name в год year
    }
    string GetFullName(int year) const {
        if (year < birth_year) {
            return "No person";
        }
        string first_name;
        string last_name;
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

    string GetFullNameWithHistory(int year) const {
        if (year < birth_year) {
            return "No person";
        }
        string first_name;
        string last_name;
        vector<string> first_name_history;
        vector<string> last_name_history;
        for (const auto& i : first_names) {
            if (year >= i.first) {
                if (!first_name.empty() && first_name != i.second) {
                    first_name_history.push_back(first_name);
                }
                first_name = i.second;
            } else {
                break;
            }
        } // получили имя на момент этого года
        for (const auto& j : last_names) {
            if (year >= j.first) {
                if (!last_name.empty() && last_name != j.second) {
                    last_name_history.push_back(last_name);
                }
                last_name = j.second;
            } else {
                break;
            }
        } // получили фамилию на момент этого года
        if (first_name.empty() && last_name.empty()) {
            return "Incognito";
        } else if (first_name.empty()) {
            return last_name + PrintVectorUni(last_name_history) + " with unknown first name";
        } else if (last_name.empty()) {
            return first_name + PrintVectorUni(first_name_history) + " with unknown last name";
        } else {
            return first_name + PrintVectorUni(first_name_history) + " " + last_name + PrintVectorUni(last_name_history);
        }
        // получить все имена и фамилии по состоянию на конец года year
    }
private:
    map<int, string> first_names;
    map<int, string> last_names;
    int birth_year;
    // приватные поля
};

int main() {
    Person person("Polina", "Sergeeva", 1960);
    for (int year : {1959, 1960}) {
        cout << person.GetFullNameWithHistory(year) << endl;
    }

    person.ChangeFirstName(1965, "Appolinaria");
    person.ChangeLastName(1967, "Ivanova");
    for (int year : {1965, 1967}) {
        cout << person.GetFullNameWithHistory(year) << endl;
    }

    return 0;
}
