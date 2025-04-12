/*
Cho một dãy số nguyên gồm N phần tử A[1], A[2], ... A[N].

Biết rằng dãy con tăng là 1 dãy A[i1],... A[ik]
thỏa mãn i1 < i2 < ... < ik và A[i1] < A[i2] < .. < A[ik].
Hãy cho biết dãy con tăng dài nhất của dãy này có bao nhiêu phần tử?

Input: Dòng 1 gồm 1 số nguyên là số N (1 ≤ N ≤ 1000). Dòng thứ 2 ghi N số nguyên A[1], A[2], .. A[N] (1 ≤ A[i] ≤ 1000).

Output: Ghi ra độ dài của dãy con tăng dài nhất.
*/

#include <iostream>
#include <vector>

int main() {
    int n, max = -1e9;
    std::cin >> n;

    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) std::cin >> a[i];

    std::vector<int> dp(n, 1);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (a[j] < a[i]) dp[i] = std::max(dp[i], dp[j] + 1);
            max = std::max(max, dp[i]);
        }
    }

    std::cout << max;
}