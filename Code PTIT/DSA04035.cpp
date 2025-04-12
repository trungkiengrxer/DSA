/*
Cho hai số nguyên không âm a và b. Hãy tính ab.

Nếu kết quả quá lớn hãy chia dư cho 10^9 + 7.

Input
Gồm không quá 20 bộ test, mỗi test ghi trên một dòng hai số a,b; a không quá 9 chữ số, b không quá 18 chữ số.
Input kết thúc khi a = b = 0

Output
Với mỗi test ghi ra kết quả tính được trên một dòng.
*/

#include <iostream>

const long long MOD = 1e9 + 7;

long long bin_pow(long long n, long long k) {
    long long result = 1;

    while (k > 0) {
        if (k % 2 == 1) result = (result * n) % MOD;
        n = (n * n) % MOD;
        k /= 2;
    }

    return result;
}

int main() {
    long long a, b;

    while (std::cin >> a >> b) {
        if (a == 0 && b == 0) break;
        std::cout << bin_pow(a, b) << "\n";
    }
}