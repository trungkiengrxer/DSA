/*
Cho mảng A[] gồm n phần tử, mảng B[] gồm m phần tử khác nhau. Các phần tử của mảng A[] và B[] chưa được sắp xếp. Hãy tìm mảng hợp và giao được sắp giữa A[] và B[]. Ví dụ với A[] = {7, 1, 5, 2, 3, 6}, B[]={3, 8, 6, 20, 7} ta có mảng hợp Union = {1, 2, 3, 5, 6, 7, 8, 20}, mảng giao Intersection = {3, 6}.

Input:
Dòng đầu tiên đưa vào số lượng bộ test T.
Những dòng kế tiếp đưa vào T bộ test. Mỗi bộ test gồm ba dòng: dòng đầu tiên đưa vào n, m là số phần tử của mảng A[] và B[]; dòng tiếp theo là n số A [i] của mảng A [];dòng tiếp theo là m số B[i] của mảng B[]; các số được viết cách nhau một vài khoảng trống.
T, n, m, A[i], B[i] thỏa mãn ràng buộc: 1≤ T ≤100; 1≤ n, m, A[i], B[i] ≤10^5.

Output:
Đưa ra kết quả mỗi test theo từng dòng.
*/

#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

int main() {
    int t;
    std::cin >> t;

    while (t--) {
        int n, m;
        std::cin >> n >> m;

        std::set<int> set, union_set, intersection_set;

        for (int i = 0; i < n; ++i) {
            int x;
            std::cin >> x;
            set.insert(x);
            union_set.insert(x);
        }

        for (int i = 0; i < m; ++i) {
            int x;
            std::cin >> x;
            union_set.insert(x);
            if (set.find(x) != set.end()) intersection_set.insert(x);
        }

        for (const int &num : union_set) std::cout << num << " ";
        std::cout << "\n";
        for (const int &num : intersection_set) std::cout << num << " ";
        std::cout << "\n";
    }
}