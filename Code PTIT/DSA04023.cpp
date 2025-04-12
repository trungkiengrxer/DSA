/*
Cho mảng A[] gồm n số nguyên dương và số K. Hãy đếm số các cặp phần tử có hiệu nhỏ hơn K. Ví dụ A[] = {1, 10, 4, 2 }, K=3 ta nhận được kết quả là 2 tương ứng với các cặp (1, 2), (4, 2).

Input:

Dòng đầu tiên đưa vào số lượng bộ test T.
Mỗi bộ test gồm hai dòng: dòng đầu tiên ghi số n và số K; dòng tiếp theo là n số A[i] ; các số được viết cách nhau một vài khoảng trống.
T, n, k, A[i] thỏa mãn ràng buộc: 1 ≤  T  ≤ 100; 1 ≤  n  ≤ 10^4; 1 ≤  k ≤ 10^3; 1 ≤  A[i]  ≤ 10^5.

Output:
Đưa ra kết quả mỗi test theo từng dòng.
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

        std::sort(a.begin(), a.end());

        long long left = 0, right = 0;

        while (left < n) {
            while (right < n && a[right] - a[left] < k) ++right;
            count += (right - left - 1);
            ++left;
        }

        std::cout << count << "\n";
    }
}