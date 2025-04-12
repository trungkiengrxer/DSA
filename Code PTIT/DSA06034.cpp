/*
Cho dãy số A[] gồm có N phần tử.
Nhiệm vụ của bạn là đếm xem có bao nhiêu cặp (i, j) mà A[i] + A[j] = K cho trước.

Input:
Dòng đầu tiên là số lượng bộ test T (T ≤ 10).
Mỗi test gồm số nguyên N và K (1≤ N ≤ 100 000, 0 ≤ K ≤ 10^9).
Dòng tiếp theo gồm N số nguyên A[i] (-10^9 ≤ A[i] ≤ 10^9).

Output:
Với mỗi test, in ra trên một dòng là đáp án thu được.
*/

#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

int main() {
    long long t;
    std::cin >> t;

    while (t--) {
        long long n, k, count = 0;
        std::cin >> n >> k;

        std::vector<long long> a(n);
        std::unordered_map<long long, long long> map;

        for (long long i = 0; i < n; ++i) {
            std::cin >> a[i];
            ++map[a[i]];
        }

        for (long long i = 0; i < n; ++i) {
            if (map.find(k - a[i]) != map.end()) count += map[k - a[i]];
            if (a[i] == k - a[i]) --count;
        }

        std::cout << count / 2 << "\n";
    }
}