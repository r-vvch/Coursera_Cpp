#include <iostream>
#include <map>
#include <set>
#include <vector>
using namespace std;

int gcd(int a, int b) {
    a = abs(a);
    b = abs(b);
    if (a < b) {
        swap(a, b);
    }
    int div = 1;
    while (b > 0) {
        a %= b;
        swap(a, b);
    }
    return a;
}

class Rational {
// Вставьте сюда реализацию класса Rational из первой части
public:
    Rational() {
        // Реализуйте конструктор по умолчанию
        p = 0;
        q = 1;
    }

    Rational(int numerator, int denominator) {
        // Реализуйте конструктор
        if (numerator == 0) {
            p = 0;
            q = 1;
        } else {
            int divider = gcd(numerator, denominator);
            if (numerator < 0 && denominator > 0 || numerator > 0 && denominator > 0) {
                p = numerator / divider;
                q = denominator / divider;
            } else {
                p = -numerator / divider;
                q = -denominator / divider;
            }
        }
    }

    int Numerator() const {
        // Реализуйте этот метод
        return p;
    }

    int Denominator() const {
        // Реализуйте этот метод
        return q;
    }

private:
    // Добавьте поля
    int p;
    int q;
};

// Вставьте сюда реализацию operator == для класса Rational из второй части

bool operator==(const Rational& a, const Rational& b) {
    if (a.Numerator() * b.Denominator() - b.Numerator() * a.Denominator() == 0) {
        return true;
    } else {
        return false;
    }
}

// Реализуйте для класса Rational оператор(ы), необходимые для использования его
// в качестве ключа map'а и элемента set'а
bool operator<(const Rational& a, const Rational& b) {
    if (a.Numerator() * b.Denominator() - b.Numerator() * a.Denominator() < 0) {
        return true;
    } else {
        return false;
    }
}

int main() {
    {
        const set<Rational> rs = {{1, 2}, {1, 25}, {3, 4}, {3, 4}, {1, 2}};
        if (rs.size() != 3) {
            cout << "Wrong amount of items in the set" << endl;
            return 1;
        }

        vector<Rational> v;
        for (auto x : rs) {
            v.push_back(x);
        }
        if (v != vector<Rational>{{1, 25}, {1, 2}, {3, 4}}) {
            cout << "Rationals comparison works incorrectly" << endl;
            return 2;
        }
    }

    {
        map<Rational, int> count;
        ++count[{1, 2}];
        ++count[{1, 2}];

        ++count[{2, 3}];

        if (count.size() != 2) {
            cout << "Wrong amount of items in the map" << endl;
            return 3;
        }
    }

    cout << "OK" << endl;
    return 0;
}
