/*
Cho dãy số A[] gồm có N phần tử.
Nhiệm vụ của bạn là hãy đếm số bộ ba (i, j, k) mà A[i] + A[j] + A[k] < K cho trước.

Input:
Dòng đầu tiên là số lượng bộ test T (T ≤ 20).
Mỗi test gồm số nguyên N và K (1≤ N ≤5000, -10^9 ≤ K ≤ 10^9).
Dòng tiếp theo gồm N số nguyên A[i] (-10^9 ≤ A[i] ≤ 10^9).

Output:
Với mỗi test, in ra trên một dòng là đáp án tìm được.
*/

#include <algorithm>
#include <iostream>
#include <vector>

int main() {
    long long t;
    std::cin >> t;

    while (t--) {
        long long n, num, count = 0;
        std::cin >> n >> num;

        std::vector<long long> a(n);
        for (long long i = 0; i < n; ++i) std::cin >> a[i];

        std::sort(a.begin(), a.end());

        for (long long i = 0; i < n; ++i) {
            long long j = i + 1, k = n - 1;

            while (j < k) {
                if (a[i] + a[j] + a[k] < num) {
                    count += (k - j);
                    ++j;
                } else
                    --k;
            }
        }

        std::cout << count << "\n";
    }
}