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
    int K;
    string query;
    cin >> M;
    for (int j = 0; j < M; j++) {
        cin >> query >> K;
        if (query == "name" && K >= 1 && K <= N) {
            cout << students[K-1].name << " " << students[K-1].surname << endl;
        } else if (query == "date" && K >= 1 && K <= N) {
            cout << students[K-1].day << "." << students[K-1].month << "." << students[K-1].year << endl;
        } else {
            cout << "bad request\n";
        }
    }

    return 0;
}
