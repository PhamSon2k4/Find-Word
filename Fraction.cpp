#include <iostream>

using namespace std;

class MyFraction {
private:
    int a, b;
public:
    MyFraction(int _a = 1, int _b = 1);
    void print() const;
    MyFraction add(const MyFraction& f) const;
    MyFraction subtract(const MyFraction& f) const;
    MyFraction multiply(const MyFraction& f) const;
    MyFraction divide(const MyFraction& f) const;
    void simplify();
    int compare(const MyFraction& f) const;
};

MyFraction::MyFraction(int _a, int _b) : a(_a), b(_b) {}
int gcd (int a, int b)
{
    if (a == 0)
        return b;
    else
        return gcd (b % a, a);
}
void MyFraction::simplify() {
    int gcd = gcd(a, b);
    a /= gcd;
    b /= gcd;
}

void MyFraction::print() const {
    if (b == 0) {
        cout << "invalid" << endl;
        return;
    }
    simplify();
    cout << a << "/" << b << endl;
}

MyFraction MyFraction::add(const MyFraction& f) const {
    int _a = a * f.b + b * f.a;
    int _b = b * f.b;
    return MyFraction(_a, _b);
}

MyFraction MyFraction::subtract(const MyFraction& f) const {
    int _a = a * f.b - b * f.a;
    int _b = b * f.b;
    return MyFraction(_a, _b);
}

MyFraction MyFraction::multiply(const MyFraction& f) const {
    int _a = a * f.a;
    int _b = b * f.b;
    return MyFraction(_a, _b);
}

MyFraction MyFraction::divide(const MyFraction& f) const {
    int _a = a * f.b;
    int _b = b * f.a;
    return MyFraction(_a, _b);
}

int MyFraction::compare(const MyFraction& f) const {
    MyFraction temp = *this;
    temp.subtract(f);
    if (temp.a > 0) {
        return 1;
    }
    else if (temp.a < 0) {
        return -1;
    }
    else {
        return 0;
    }
}

int main() {
    MyFraction x(1, 3), y(1, 3);
    x = x.add(y);
    x.print();
    return 0;
}
