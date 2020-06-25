#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

int main() {
    ifstream input("input.txt");
    if (input) {
        int strings = 0, rows = 0;
        input >> strings >> rows;
        int number;
        for (int i = 0; i < strings; i++) {
            for (int j = 0; j < rows; j++) {
                input >> number;
                cout << setw(10) << number;
                if (j != rows - 1) {
                    cout << " ";
                }
                input.ignore(1);
            }
            if (i != strings - 1) {
                cout << "\n";
            }
        }
        while (input >> number) {

        }
    }

    return 0;
}