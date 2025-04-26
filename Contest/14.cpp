#include <iostream>
#include <vector>

std::vector<long long> result(10);
std::vector<long long> count_a(10);
std::vector<long long> count_b(10);

void count(long long n, std::vector<long long> &freq) {
    int k = 1;
    while (n >= k) {
        int right = n % k;
        int mid = (n / k) % 10;
        int left = n / (k * 10);

        for (int i = 0; i < 10; ++i) freq[i] += left * k;
        for (int i = 0; i < mid; ++i) freq[i] += k;
        
        freq[mid] += right + 1;
        if (k >= 1) freq[0] -= k;
        k *= 10;
    }
}

void solve(long long a, long long b) {
    count(b, count_b);
    count(a - 1, count_a);

    for (long long i = 0; i < 10; ++i) result[i] = count_b[i] - count_a[i];

    for (long long i = 0; i < 10; ++i) std::cout << result[i] << " ";
    std::cout << "\n";
}

int main() {
    long long t;
    std::cin >> t;

    while (t--) {
        result.assign(10, 0);
        count_a.assign(10, 0);
        count_b.assign(10, 0);

        long long a, b;
        std::cin >> a >> b;

        solve(a, b);
    }
}