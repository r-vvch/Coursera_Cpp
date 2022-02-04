#include <iostream>
#include <iomanip>
#include <map>
#include <set>

using namespace std;

bool is_number(const std::string& s)
{
    std::string::const_iterator it = s.begin();
    while (it != s.end() && std::isdigit(*it)) ++it;
    return !s.empty() && it == s.end();
}

class Date {
public:
    Date(const string& s) {
        int i = 0;
        try {
            while (s[i] != '-') {
                i++;
            }
            if (!is_number(s.substr(0, i))) {
                throw range_error("Wrong date format: " + s + "\n");
            }
            year = stoi(s.substr(0, i));
            i++;
            int pos = i;
            while (s[i] != '-') {
                i++;
            }
            if (!is_number(s.substr(pos, i - pos))) {
                throw range_error("Wrong date format: " + s + "\n");
            }
            month = stoi(s.substr(pos, i - pos));
            if (month < 1 || month > 12) {
                throw range_error("Month value is invalid: " + to_string(month) + "\n");
            }
            if (!is_number(s.substr(i + 1, s.length() - i - 1))) {
                throw range_error("Wrong date format: " + s + "\n");
            }
            day = stoi(s.substr(i + 1, s.length() - i - 1));
            if (day < 1 || day > 31) {
                throw range_error("Day value is invalid: " + to_string(month) + "\n");
            }
        } catch (runtime_error& e) {
            cout << e.what();
        }
//        } catch (exception& e) {
//            cout << "Wrong date format: " + s + "\n";
//        }
    }
    int GetYear() const {
        return year;
    }
    int GetMonth() const {
        return month;
    }
    int GetDay() const {
        return day;
    }

private:
    int year;
    int month;
    int day;
};

bool operator<(const Date& lhs, const Date& rhs) {
    if (lhs.GetYear() == rhs.GetYear()) {
        if (lhs.GetMonth() == rhs.GetMonth()) {
            return lhs.GetDay() < lhs.GetDay();
        } else {
            return lhs.GetMonth() < rhs.GetMonth();
        }
    } else {
        return lhs.GetYear() < rhs.GetYear();
    }
}

class Database {
public:
    void AddEvent(const Date& date, const string& event) {
        try {
            events[date].insert(event);
        } catch (exception& e) {
            events[date] = {};
            events[date].insert(event);
        }
    }

    bool DeleteEvent(const Date& date, const string& event) {
        try {
            if (events[date].count(event) == 1) {
                events[date].erase(event);
                cout << "Deleted successfully\n";
                return true;
            } else {
                cout << "Event not found\n";
                return false;
            }
        } catch (exception& e) {
            cout << "Event not found\n";
            return false;
        }
    }

    int DeleteDate(const Date& date) {
        try {
            size_t n = events[date].size();
            events.erase(date);
            cout << "Deleted " + to_string(n) + " events\n";
            return int(n);
        } catch (exception& e) {
            cout << "Deleted 0 events\n";
            return 0;
        }
    }

    set<string> Find(const Date& date) const {
        for (const auto& i : events.at(date)) {
            cout << i << "\n";
        }
        return events.at(date);
    }

    void Print() const {
        for (const auto& i : events) {
            for (const auto& j : events.at(i.first)) {
                cout << setw(4) << setfill('0') << i.first.GetYear() << "-"
                     << setw(2) << setfill('0') << i.first.GetMonth() << "-"
                     << setw(2) << setfill('0') << i.first.GetDay()
                     << " " << j << "\n";
            }
        }
    }

private:
    map<Date, set<string>> events = {};
};

int main() {
    Database db;

    string command;
    while (getline(cin, command)) {
        string token = command.substr(0, command.find(' '));
        string command_rest = command.substr(command.find(' ') + 1, command.length() - command.find(' '));
        if (token == "Add") {
            string date = command_rest.substr(0, command_rest.find(' '));
            string event = command_rest.substr(command_rest.find(' ') + 1,
                                               command_rest.length() - command_rest.find(' ') - 1);
            Date date_date = Date(date);
            db.AddEvent(date_date, event);
        } else if (token == "Del") {
            if (command_rest.find(' ') == string::npos) {
                db.DeleteDate(Date(command_rest));
            } else {
                string date = command_rest.substr(0, command_rest.find(' '));
                string event = command_rest.substr(command_rest.find(' ') + 1,
                                                   command_rest.length() - command_rest.find(' ') - 1);
                Date date_date = Date(date);
                db.DeleteEvent(date_date, event);
            }
        } else if (token == "Find") {
            db.Find(Date(command_rest));
        } else if (token == "Print") {
            db.Print();
        } else if (!token.empty()) {
            cout << "Unknown command: " + command + "\n";
        }
    }

    return 0;
}