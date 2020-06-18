#include <iostream>

using namespace std;

struct Specialization {
    explicit Specialization(string new_name) {
        name = new_name;
    }
    string name;
};

struct Course {
    explicit Course(string new_name) {
        name = new_name;
    }
    string name;
};

struct Week {
    explicit Week(string new_name) {
        name = new_name;
    }
    string name;
};

struct LectureTitle {
    LectureTitle(const Specialization& new_specialization, const Course& new_course, const Week& new_week) {
        specialization = new_specialization.name;
        course = new_course.name;
        week = new_week.name;
    }
    string specialization;
    string course;
    string week;
};

int main() {
    LectureTitle title1(
            Specialization("C++"),
            Course("White belt"),
            Week("4th")
    );

//    LectureTitle title2("C++", "White belt", "4th");
//
//    LectureTitle title3(string("C++"), string("White belt"), string("4th"));
//
//    LectureTitle title4 = {"C++", "White belt", "4th"};
//
//    LectureTitle title5 = {{"C++"}, {"White belt"}, {"4th"}};
//
//    LectureTitle title6(
//            Course("White belt"),
//            Specialization("C++"),
//            Week("4th")
//    );
//
//    LectureTitle title7(
//            Specialization("C++"),
//            Week("4th"),
//            Course("White belt")
//    );

    return 0;
}

