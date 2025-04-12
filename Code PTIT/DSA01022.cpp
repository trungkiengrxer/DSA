/*
Cho một hoán vị của N số nguyên dương đầu tiên.

Hãy xác định xem đó là hoán vị thứ bao nhiêu nếu liệt kê theo thứ tự tăng dần (tính từ 1).

Input
• Dòng đầu ghi số T là số bộ test (T < 10)
• Mỗi bộ test gồm 2 dòng
• Dòng đầu ghi số nguyên dương N (3 < N < 10)
• Dòng tiếp theo ghi một hoán vị của các số nguyên dương từ 1 đến N.  

Output
• Với mỗi bộ test, ghi ra trên một dòng số thứ tự của hoán vị (tính từ 1, theo thứ tự liệt kê tăng dần).
*/

#include <iostream>
#include <vector>

std::vector<long long> fact(11);

void factorial() {
    fact[0] = 1;
    fact[1] = 1;
    for (long long i = 2; i < 11; ++i) fact[i] = fact[i - 1] * i;
}

long long find(long long n, std::vector<long long> &a) {
    long long result = 1;
    std::vector<bool> visited(n + 1, false);

    for (long long i = 0; i < n; ++i) {
        long long count = 0;
        for (long long j = 1; j < a[i]; ++j) {
            if (!visited[j]) ++count;
        }
        visited[a[i]] = true;
        result += count * fact[n - i - 1];
    }

    return result;
}

int main() {
    factorial();
    long long t;
    std::cin >> t;

    while (t--) {
        long long n;
        std::cin >> n;

        std::vector<long long> a(n);
        for (long long i = 0; i < n; ++i) std::cin >> a[i];

        std::cout << find(n, a) << "\n";
    }
}