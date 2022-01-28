#include <iostream>
#include <exception>
using namespace std;

class Rational {
public:
    Rational() {
        p = 0;
        q = 1;
    }

    static int gcd(int a, int b) {
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

    Rational(int numerator, int denominator) {
        if (denominator == 0) {
            throw invalid_argument("Denominator equals 0");
        }
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
        return p;
    }

    int Denominator() const {
        return q;
    }

private:
    int p;
    int q;
};

Rational operator / (const Rational& a, const Rational& b) {
    if (b.Numerator() == 0) {
        throw domain_error("Divider equals 0");
    }
    return Rational(a.Numerator() * b.Denominator(),
                    a.Denominator() * b.Numerator());
}

int main() {
    try {
        Rational r(1, 0);
        cout << "Doesn't throw in case of zero denominator" << endl;
        return 1;
    } catch (invalid_argument&) {
    }

    try {
        auto x = Rational(1, 2) / Rational(0, 1);
        cout << "Doesn't throw in case of division by zero" << endl;
        return 2;
    } catch (domain_error&) {
    }

    cout << "OK" << endl;
    return 0;
}
