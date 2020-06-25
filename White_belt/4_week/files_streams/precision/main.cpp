#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

int main() {
    ifstream input("input.txt");
    if (input) {
        double number;
        cout << fixed << setprecision(3);
        while (input >> number) {
            cout << number << endl;
        }
    }

    return 0;
}