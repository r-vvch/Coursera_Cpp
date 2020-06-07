#include <iostream>
#include <vector>
#include "main.cpp"

Weather GetMayWeather(int day) {
    if (day == 9) {
        cout << 'b';
        return {"clear", 10};
    } else {
        cout << 'b';
        return {"cloudy", 10};
    }
}

int main() {
    vector<int> days(2, 1);
    for (int day : days) {
        cout << 'a';
        Weather weather = GetMayWeather(day);
        cout << 'e';
    }
    cout << 'f';
    return 0;
}
