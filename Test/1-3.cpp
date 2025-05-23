#include <cmath>
#include <iostream>

using namespace std;
long long gcd(long long a, long long b) {
    a = abs(a);
    b = abs(b);
    while (b != 0) {
        long long r = a % b;
        a = b;
        b = r;
    }
    return a;
}

long long lcm(long long a, long long b) { return a * b / gcd(a, b); }

struct PhanSo {
    long long tu;
    long long mau;
};

void process(PhanSo a, PhanSo b) {

    long long tu_a = a.tu * b.mau;
    long long mau = a.mau * b.mau;
    long long tu_b = b.tu * a.mau;

    PhanSo c;
    c.tu = tu_a + tu_b;
    c.mau = mau;

    long long gcd_tu_mau = gcd(c.tu, c.mau);
    c.tu /= gcd_tu_mau;
    c.mau /= gcd_tu_mau;

    c.tu *= c.tu;
    c.mau *= c.mau;

    long long gcd_c = gcd(c.tu, c.mau);
    c.tu /= gcd_c;
    c.mau /= gcd_c;

    cout << c.tu << "/" << c.mau << " ";

    PhanSo d;
    d.tu = a.tu * b.tu * c.tu;
    d.mau = a.mau * b.mau * c.mau;

    long long gcd_d = gcd(d.tu, d.mau);
    d.tu /= gcd_d;
    d.mau /= gcd_d;

    cout << d.tu << "/" << d.mau << "\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        PhanSo A;
        PhanSo B;
        cin >> A.tu >> A.mau >> B.tu >> B.mau;
        process(A, B);
    }
}