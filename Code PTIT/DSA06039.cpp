/*
Cho dãy số A[] gồm có N phần tử. Nhiệm vụ của bạn là hãy tìm số xuất hiện nhiều hơn 1 lần trong dãy số và số thứ tự là nhỏ nhất.

Input:
Dòng đầu tiên là số lượng bộ test T (T ≤ 10).
Mỗi test gồm số nguyên N (1≤ N ≤ 100 000), số lượng phần tử trong dãy số ban đầu.
Dòng tiếp theo gồm N số nguyên A[i] (0 ≤ A[i] ≤ 10^9).

Output: 
Với mỗi test in ra đáp án của bài toán trên một dòng. Nếu không tìm được đáp án, in ra “NO”.
*/

#include <iostream>
#include <vector>
#include <unordered_map>

int main() {
    int t;
    std::cin >> t;

    while (t--) {
        int n;
        bool found = false;
        std::cin >> n;

        std::vector<int> a(n);
        std::unordered_map<int, int> map;

        for (int i = 0; i < n; ++i) {
            std::cin >> a[i];
            ++map[a[i]];
        }

        for (int i = 0; i < n; ++i) {
            if (map[a[i]] > 1) {
                std::cout << a[i] << "\n";
                found = true;
                break;
            }
        } 

        if (!found) std::cout << "NO\n";

    }
}