#include <iostream>
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
public:
    Rational() {
        p = 0;
        q = 1;
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

bool operator == (const Rational& a, const Rational& b) {
    return a.Numerator() == b.Numerator() && a.Denominator() == b.Denominator();
}

Rational operator + (const Rational& a, const Rational& b) {
    return Rational(a.Numerator() * b.Denominator() + b.Numerator() * a.Denominator(),
                    a.Denominator() * b.Denominator());
}

Rational operator - (const Rational& a, const Rational& b) {
    return Rational(a.Numerator() * b.Denominator() - b.Numerator() * a.Denominator(),
                    a.Denominator() * b.Denominator());
}

Rational operator * (const Rational& a, const Rational& b) {
    return Rational(a.Numerator() * b.Numerator(),
                    a.Denominator() * b.Denominator());
}

Rational operator / (const Rational& a, const Rational& b) {
    if (b.Numerator() == 0) {
        throw domain_error("Divider equals 0");
    }
    return Rational(a.Numerator() * b.Denominator(),
                    a.Denominator() * b.Numerator());
}

ostream& operator << (ostream& stream, const Rational& a) {
    stream << a.Numerator() << "/" << a.Denominator();
    return stream;
}

istream& operator >> (istream& stream, Rational& a) {
    int n, d;
    char c;
    if (stream) {
        stream >> n >> c >> d;
        if (stream) {
            if (c == '/') {
                a = Rational(n, d);
            } else {
                stream.setstate(ios_base::failbit);
            }
        }
    }
    return stream;
}

bool operator < (const Rational& a, const Rational& b) {
    if (a.Numerator() * b.Denominator() - b.Numerator() * a.Denominator() < 0) {
        return true;
    } else {
        return false;
    }
}

int main() {
    Rational r1, r2;
    char op;
    try {
        cin >> r1 >> op >> r2;
        if (op == '+') {
            cout << r1 + r2;
        } else if (op == '-') {
            cout << r1 - r2;
        } else if (op == '*') {
            cout << r1 * r2;
        } else if (op == '/') {
            try {
                cout << r1 / r2;
            } catch (exception& ex) {
                cout << "Division by zero";
            }
        }
    } catch (exception& ex) {
        cout << "Invalid argument";
    }
        return 0;
}