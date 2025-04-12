/*
Cho mảng A[] gồm n phần tử và số k. Đếm tất cả các cặp phần tử của mảng có tổng bằng k. Ví dụ A[] = {1, 5, 3, 4, 2 }, k = 7 ta có kết quả là 2 cặp (3, 4), (5, 2).

Input:
Dòng đầu tiên đưa vào số lượng bộ test T.
Những dòng kế tiếp đưa vào T bộ test. Mỗi bộ test gồm hai dòng: dòng đầu tiên đưa vào n là số phần tử của mảng A[] và k; dòng tiếp theo là n số A[i] của mảng A[]các số được viết cách nhau một vài khoảng trống.
T, n, k, A[i] thỏa mãn ràng buộc: 1≤ T ≤100; 1≤ n ≤100; 0≤ k ≤100, 0≤ A[i] ≤10^3.

Output:
Đưa ra kết quả mỗi test theo từng dòng.
*/

#include <iostream>
#include <unordered_map>
#include <vector>

int main() {
    int t;
    std::cin >> t;

    while (t--) {
        int n, k, count = 0;
        std::cin >> n >> k;

        std::vector<int> a(n);
        std::unordered_map<int, int> map;

        for (int i = 0; i < n; ++i) {
            std::cin >> a[i];
            ++map[a[i]];
        }

        for (const int &num : a) {
            if (map.find(k - num) != map.end()) count += map[k - num];
            if (k - num == num) --count;
        }

        std::cout << count / 2 << "\n";
    }
}