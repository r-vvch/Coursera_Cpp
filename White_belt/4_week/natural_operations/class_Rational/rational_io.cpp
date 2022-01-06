#include <iostream>
#include <sstream>
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

// Реализуйте для класса Rational операторы << и >>
ostream& operator<<(ostream& stream, const Rational& a) {
    stream << a.Numerator() << "/" << a.Denominator();
    return stream;
}

bool is_number(const std::string& s)
{
    std::string::const_iterator it = s.begin();
    while (it != s.end() && std::isdigit(*it)) {
        ++it;
    }
    return !s.empty() && it == s.end();
}

istream& operator>>(istream& stream, Rational& a) {
    string raw_str, divider;
    int num = 0, den = 0, divider_pos = 0;
    if (stream.rdbuf()->in_avail() != 0) {
        stream >> raw_str;
        if (is_number(raw_str) ||
                is_number(raw_str.substr(1, raw_str.length() - 1))) {
            if (stream.rdbuf()->in_avail() != 0) {
                string raw_str_1;
                stream >> raw_str_1;
                if (raw_str_1 == "/") {
                    if (stream.rdbuf()->in_avail() != 0) {
                        string raw_str_2;
                        stream >> raw_str_2;
                        if (is_number(raw_str_2) ||
                                is_number(raw_str_2.substr(1, raw_str_2.length() - 1))) {
                            a = Rational(stoi(raw_str), stoi(raw_str_2));
                            return stream;
                        }
                    }
                }
            } else {
                return stream;
            }
        }
        bool have_slash = false;
        for (int i = 0; i < raw_str.length() - 1; i++) {
            if (raw_str[i] == '/') {
                have_slash = true;
                divider_pos = i;
                break;
            }
        }
        int i = 0, num_erased = 0;
        while (i < raw_str.length() - i - num_erased) {
            if (raw_str[i] == ' ') {
                raw_str.erase(i, 1);
                num_erased++;
            }
            i++;
        }
        string num_raw, den_raw;
        if (have_slash && divider_pos != 0 && divider_pos != raw_str.length() - 1) {
            if (is_number(raw_str.substr(0, divider_pos))) {
                num_raw = raw_str.substr(0, divider_pos);
                num = stoi(num_raw);
            } else if (is_number(raw_str.substr(1, divider_pos - 1))  &&
                       (raw_str[0] == '-' || raw_str[0] == '+')) {
                num_raw = raw_str.substr(1, divider_pos - 1);
                num = - stoi(num_raw);
            } else {
                return stream;
            }
            if (is_number(raw_str.substr(divider_pos + 1, raw_str.length() - divider_pos))) {
                den_raw = raw_str.substr(divider_pos + 1, raw_str.length() - divider_pos);
                den = stoi(den_raw);
            } else if (is_number(raw_str.substr(divider_pos + 2, raw_str.length() - divider_pos)) &&
                       (raw_str[divider_pos + 1] == '-' || raw_str[divider_pos + 1] == '+')) {
                den_raw = raw_str.substr(divider_pos + 2, raw_str.length() - divider_pos);
                den = - stoi(den_raw);
            } else {
                return stream;
            }
            a = Rational(num, den);
            return stream;
        }
    } else {
        stream >> raw_str;
    }
    return stream;
}

int main() {
    {
        ostringstream output;
        output << Rational(-6, 8);
        if (output.str() != "-3/4") {
            cout << "Rational(-6, 8) should be written as \"-3/4\"" << endl;
            return 1;
        }
    }

    {
        istringstream input("5/7");
        Rational r;
        input >> r;
        bool equal = r == Rational(5, 7);
        if (!equal) {
            cout << "5/7 is incorrectly read as " << r << endl;
            return 2;
        }
    }

    {
        istringstream input("");
        Rational r;
        bool correct = !(input >> r);
        if (!correct) {
            cout << "Read from empty stream works incorrectly" << endl;
            return 3;
        }
    }

    {
        istringstream input("5/7 10/8");
        Rational r1, r2;
        input >> r1 >> r2;
        bool correct = r1 == Rational(5, 7) && r2 == Rational(5, 4);
        if (!correct) {
            cout << "Multiple values are read incorrectly: " << r1 << " " << r2 << endl;
            return 4;
        }

        input >> r1;
        input >> r2;
        correct = r1 == Rational(5, 7) && r2 == Rational(5, 4);
        if (!correct) {
            cout << "Read from empty stream shouldn't change arguments: " << r1 << " " << r2 << endl;
            return 5;
        }
    }

    {
        istringstream input1("1*2"), input2("1/"), input3("/4");
        Rational r1, r2, r3;
        input1 >> r1;
        input2 >> r2;
        input3 >> r3;
        bool correct = r1 == Rational() && r2 == Rational() && r3 == Rational();
        if (!correct) {
            cout << "Reading of incorrectly formatted rationals shouldn't change arguments: "
                 << r1 << " " << r2 << " " << r3 << endl;

            return 6;
        }
    }

    {
        istringstream input("1/-2");
        Rational r;
        input >> r;
        bool equal = r == Rational(1, -2);
        if (!equal) {
            cout << "1/-2 is incorrectly read as " << r << endl;
            return 7;
        }
    }

    {
        istringstream input1("1/-2");
        Rational r1(2,3), r2(3, -7);
        input1 >> r1 >> r2;
        cout << r1 << " " << r2 << endl;
    }

    {
        istringstream input1("1 / -2");
        Rational r1(2,3), r2(3, -7);
        input1 >> r1 >> r2;
        cout << r1 << " " << r2 << endl;
    }

    cout << "OK" << endl;
    return 0;
}
