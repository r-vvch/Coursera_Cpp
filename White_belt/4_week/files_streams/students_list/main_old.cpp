#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Student {
    string name;
    string surname;
    int day;
    int month;
    int year;
};

int main() {
//    ввод студентов
    int N;
    cin >> N;
    vector<Student> students(N);
    for (int i = 0; i < N; i++) {
        cin >> students[i].name >> students[i].surname >> students[i].day >> students[i].month >> students[i].year;
    }

//    ввод запросов
    int M;
    string query;
    int K;
    cin >> M;
    for (int j = 0; j < M; j++) {
        if (cin) {
            cin >> query;
//            по условию запрос должен содержать либо слово name, либо слово date
            if (cin) {
                cin >> K;
                if (query != "name" && query != "date") {
                    cout << "bad request\n";
                    continue;
                }
//                по условию число K должно быть от 1 до N
                if (K < 1 || K > N) {
                    cout << "bad request\n";
                    continue;
                }
            } else {
                cout << "bad request no cin\n";
                continue;
            }
        } else {
            cout << "bad request no cin\n";
            continue;
        }
        if (query == "name") {
            cout << students[K-1].name << " " << students[K-1].surname << endl;
        }
        if (query == "date") {
            cout << students[K-1].day << "." << students[K-1].month << "." << students[K-1].year << endl;
        }
    }

    return 0;
}
