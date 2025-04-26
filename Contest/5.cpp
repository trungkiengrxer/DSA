#include <iostream>
#include <string>
#include <vector>

std::vector<long long> len(46);
std::vector<long long> count_a(46);

void gen() {
    len[0] = len[1] = 1;
    count_a[0] = 1;
    count_a[1] = 0;
    for (long long i = 2; i < 46; ++i) {
        len[i] = len[i - 1] + len[i - 2];
        count_a[i] = count_a[i - 1] + count_a[i - 2];
    }
}

long long count(long long n, long long k) {
    if (n == 0) return 1;
    if (n == 1) return 0;

    if (k <= len[n - 1])
        return count(n - 1, k);
    else
        return count_a[n - 1] + count(n - 2, k - len[n - 1]);
}

int main() {
    gen();
    long long t;
    std::cin >> t;

    while (t--) {
        long long n, k;
        std::cin >> n >> k;

        std::cout << count(n, k) << "\n";
    }
}