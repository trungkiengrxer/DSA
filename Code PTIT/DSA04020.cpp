/*
Cho dãy số A[] gồm có N phần tử đã được sắp xếp tăng dần và số K.

Nhiệm vụ của bạn là kiểm tra xem số K có xuất hiện trong dãy số hay không. Nếu có hãy in ra vị trí trong dãy A[], nếu không in ra “NO”.

Input:

Dòng đầu tiên là số lượng bộ test T (T ≤ 10).
Mỗi test bắt đầu bằng số nguyên N và K (N ≤ 100 000, 0 ≤ K ≤ 10^6).
Dòng tiếp theo gồm N số nguyên A[i] (0 ≤ A[i] ≤ 10^6), các phần tử là riêng biệt.

Output:
Với mỗi test in ra trên một dòng đáp án tìm được.
*/

#include <iostream>
#include <vector>

int binary_search(int n, int k, std::vector<int> &a) {
    int left = 0, right = n - 1, index = -1;

    while (left <= right) {
        int mid = (left + right) / 2;

        if (a[mid] == k) {
            index = mid + 1;
            break;
        } else if (a[mid] < k) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return index;
}

int main() {
    int t;
    std::cin >> t;

    while (t--) {
        int n, k;
        std::cin >> n >> k;

        std::vector<int> a(n);
        for (int i = 0; i < n; ++i) std::cin >> a[i];

        int index = binary_search(n, k, a);

        if (index == -1) {
            std::cout << "NO" << "\n";
            continue;
        }

        std::cout << index << "\n";
    }
}
