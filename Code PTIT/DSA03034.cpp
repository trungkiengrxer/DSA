/*
Cho dãy số A[], B[] và C[] là dãy không giảm và có lần lượt N, M, K phần tử. Nhiệm vụ của bạn là hãy tìm các phần tử chung của 3 dãy số này.

Input:
Dòng đầu tiên là số lượng bộ test T (T ≤ 20).
Mỗi test gồm số nguyên N, M và K (1≤ N, M, K ≤ 100 000).
Dòng tiếp theo gồm N số nguyên A[i], rồi M số nguyên B[i] và K số nguyên C[i].
(0 ≤ A[i], B[i], C[i] ≤ 10^9).

Output:
Với mỗi test, in ra trên một dòng là đáp án thu được. Nếu không tìm được đáp án, in ra “NO”.
*/

#include <iostream>
#include <vector>

int main() {
    int t;
    std::cin >> t;

    while (t--) {
        int n, m, k;

        std::cin >> n >> m >> k;

        std::vector<int> result;
        std::vector<int> a(n), b(m), c(k);

        for (int i = 0; i < n; ++i) std::cin >> a[i];
        for (int i = 0; i < m; ++i) std::cin >> b[i];
        for (int i = 0; i < k; ++i) std::cin >> c[i];

        int i = 0, j = 0, l = 0;
        while (i < n && j < m && l < k) {
            if (a[i] == b[j] && b[j] == c[l]) {
                result.push_back(a[i]);
                ++i, ++j, ++l;
            } else {
                if (a[i] < b[j])
                    ++i;
                else if (b[j] < c[l])
                    ++j;
                else
                    ++l;
            }
        }

        if (result.empty()) {
            std::cout << "NO" << "\n";
            continue;
        }

        for (const auto &num : result) std::cout << num << " ";
        std::cout << "\n";
    }
}