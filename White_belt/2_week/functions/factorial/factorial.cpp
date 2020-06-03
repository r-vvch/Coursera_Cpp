int Factorial(int x) {
    int fact = x;
    if (x > 0) {
        for (int i = 2; i < x; ++i) {
            fact *= i;
//            cout << fact << endl;
        }
        return fact;
    } else {
        return 1;
    }
}