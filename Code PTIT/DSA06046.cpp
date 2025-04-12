/*
Cho dãy số A[] gồm có N phần tử. Bạn cần tìm chênh lệch nhỏ nhất giữa hai phần tử bất kì trong dãy số đã cho.

Input:
Dòng đầu tiên là số lượng bộ test T (T ≤ 10).
Mỗi test gồm số nguyên N (1≤ N ≤ 100 000).
Dòng tiếp theo gồm N số nguyên A[i] (0 ≤ A[i] ≤ 10^9).

Output:
Với mỗi test, in ra trên một dòng là đáp án tìm được.
*/

#include <algorithm>
#include <iostream>
#include <vector>

int main() {
    int t;
    std::cin >> t;

    while (t--) {
        int n, min = 1e9;
        std::cin >> n;

        std::vector<int> a(n);
        for (int i = 0; i < n; ++i) std::cin >> a[i];

        std::sort(a.begin(), a.end());

        for (int i = 1; i < n; ++i) {
            min = std::min(min, abs(a[i] - a[i - 1]));
        }

        std::cout << min << "\n";
    }
}