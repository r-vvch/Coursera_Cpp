#include <iostream>
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

// Реализуйте для класса Rational операторы * и /
Rational operator*(const Rational& a, const Rational& b) {
    return Rational(a.Numerator() * b.Numerator(),
                    a.Denominator() * b.Denominator());
}

Rational operator/(const Rational& a, const Rational& b) {
    return Rational(a.Numerator() * b.Denominator(),
                    a.Denominator() * b.Numerator());
}

int main() {
    {
        Rational a(2, 3);
        Rational b(4, 3);
        Rational c = a * b;
        bool equal = c == Rational(8, 9);
        if (!equal) {
            cout << "2/3 * 4/3 != 8/9" << endl;
            return 1;
        }
    }

    {
        Rational a(5, 4);
        Rational b(15, 8);
        Rational c = a / b;
        bool equal = c == Rational(2, 3);
        if (!equal) {
            cout << "5/4 / 15/8 != 2/3" << endl;
            return 2;
        }
    }

    cout << "OK" << endl;
    return 0;
}