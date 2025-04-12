/*
Cho dãy số A[] gồm có N phần tử. Bạn cần tìm 2 vị trí i, j sao cho j-i lớn nhất và A[j] > A[i].

Input:
Dòng đầu tiên là số lượng bộ test T (T ≤ 10).
Mỗi test gồm số nguyên N (1≤ N ≤ 100 000).
Dòng tiếp theo gồm N số nguyên A[i] (-10^6 ≤ A[i] ≤ 10^6).

Output:
Với mỗi test, in ra trên một dòng là giá trị của hiệu j-i tìm được.
*/

#include <algorithm>
#include <iostream>
#include <vector>

bool comparator(std::pair<int, int> a, std::pair<int, int> b) { return a.first < b.first; }

int main() {
    int t;
    std::cin >> t;

    while (t--) {
        int n;
        std::cin >> n;

        std::vector<std::pair<int, int>> a(n);
        for (int i = 0; i < n; ++i) {
            std::cin >> a[i].first;
            a[i].second = i;
        }

        std::sort(a.begin(), a.end(), comparator);

        int max = -1e9;
        int i = a[0].second;

        for (int j = 1; j < n; ++j) {
            max = std::max(max, a[j].second - i);
            i = std::min(i, a[j].second);
        }

        std::cout << max << "\n";
    }
}